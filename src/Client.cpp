#include "Client.hpp"

Client::Client() : socket_fd(-1), ip_address(""), nickname(""), username(""), buffer(""), is_registered(false), is_authenticated(false) {}

Client::Client(Client const & other) : socket_fd(other.socket_fd), ip_address(other.ip_address), nickname(other.nickname), username(other.username), buffer(other.buffer), is_registered(other.is_registered), is_authenticated(other.is_authenticated)
{}

Client & Client::operator=(Client const & other)
{
	if(this != &other)
	{
		socket_fd = other.socket_fd;
		ip_address = other.ip_address;
		nickname = other.nickname;
		username = other.username;
		buffer = other.buffer;
		is_registered = other.is_registered;
		is_authenticated = other.is_authenticated;
	}
	return *this;
}

Client::Client(int socket_fd, const std::string & ip_address) : socket_fd(socket_fd), ip_address(ip_address), nickname(""), username(""), buffer(""), is_registered(false), is_authenticated(false)
{}

Client::~Client(){}

bool Client::hasCompleteLine() const
{
	return buffer.find('\n') != std::string::npos;
}

//removing excess \r characters right now with an extra two lines instead
//of dealing with it later like the Yerevan project. It only costs two
//extra lines. 
std::string Client::extractLine()
{
	size_t pos = buffer.find('\n');
	std::string line = buffer.substr(0, pos);
	buffer.erase(0, pos + 1);
	if(!line.empty() && line[line.size() - 1] == '\r')
		line.erase(line.size() - 1);
	return line;
}
