#include "Server.hpp"
#include "Client.hpp"
#include "ServerException.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <poll.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sstream>
#include <cctype>

//constructor
Server::Server(int port, std::string password) : port(port), password(password)
{
	master_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(master_fd < 0)
		throw ServerException("Socket() failed");
	int opt = 1;
	setsockopt(master_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	fcntl(master_fd, F_SETFL, O_NONBLOCK);

	//create a socket
	struct sockaddr_in addr;
	std::memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
	
	//bind
	if(bind(master_fd, (struct sockaddr*)&addr, sizeof(addr)) <0 )
		throw ServerException("bind() failed");

	//listen
	listen(master_fd, 10);
	std::cout << "server listening on port " << port << std::endl;

	struct pollfd pfd;
	pfd.fd = master_fd;
	pfd.events = POLLIN;
	fds.push_back(pfd);
}

//destructor
Server::~Server(){}

//functions
void Server::sendReply(int client_fd, const std::string& message)
{
	std::string msg = message + "\r\n";
	send(client_fd, msg.c_str(), msg.size(), 0);
}

void Server::processCommand(Client* client, const std::string& line)
{
	std::istringstream iss(line);
	std::string command;
	iss >> command;
	std::string params;
	std::getline(iss >> std::ws, params);
	for(size_t i = 0; i < command.length(); ++i)
		command[i] = std::toupper(command[i]);
	if(command == "PASS")
	{
		if(client->isAuthenticated())
		{
			sendReply(client->getSocketFd(), "462: You may not reregister");
			return;	
		}
		if(params == password)
		{
			client->setAuthenticated(true);
			sendReply(client->getSocketFd(), "Password accepted");
		}else
		{
			sendReply(client->getSocketFd(), "464 : Password incorrect");
		}
	}}

//the bones of this entire thing
void Server::run()
{
while(true)
	{
		int ret = poll(&fds[0], fds.size(), -1);
		if(ret < 0){
			std::cerr << "poll() failed" << std::endl;
			break;
		}
		for(size_t i = 0; i < fds.size(); i++)
		{
			if(!(fds[i].revents & POLLIN))
				continue;
			if(fds[i].fd == master_fd)
			{
				struct sockaddr_in client_addr;
				socklen_t client_len = sizeof(client_addr);
				//accept
				int client_fd = accept(master_fd, (struct sockaddr*)&client_addr, &client_len );
				if(client_fd < 0)
					continue;
					//do not create a client for unusable fd
				if(fcntl(client_fd, F_SETFL, O_NONBLOCK) < 0)
				{
					close(client_fd);
					continue;
				}
				Client* newClient = new Client(client_fd, inet_ntoa(client_addr.sin_addr));
				addClient(client_fd, newClient);
				std::cout << "New client connected: fd=" << client_fd << std::endl;
				struct pollfd cpfd; 
				cpfd.fd = client_fd;
				cpfd.events = POLLIN;
				fds.push_back(cpfd);
			
			}
			else
			{
				char buf[512];
				int n = recv(fds[i].fd, buf, sizeof(buf) - 1, 0);
				if(n <= 0)
				{
					std::cout << "Client fd=" << fds[i].fd << " disconnected" <<std::endl;
					removeClient(fds[i].fd);
					close(fds[i].fd);
					fds.erase(fds.begin() + i);
					--i;
				}	
				else
				{
					buf[n]  = '\0';
					//get client object for this fd
					Client* client = clients[fds[i].fd];
					if(!client)continue;

					//append the raw chunk to clients butfer
					client->appendToBuffer(buf, n);
					while(client->hasCompleteLine())
					{
						std::string line = client->extractLine();
						processCommand(client, line);}
				}
			}
		}
	}
}

        void Server::addClient(int fd, Client* client)
	{
		clients[fd] = client;
	}

	void Server::removeClient(int fd)
	{
		std::map<int, Client*>::iterator it = clients.find(fd);
		if(it != clients.end())
		{
			delete it->second;
			clients.erase(it);
		}
	}

