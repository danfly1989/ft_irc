/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwaschwi <zwaschwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:15:24 by zwaschwi          #+#    #+#             */
/*   Updated: 2026/07/21 16:36:55 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <poll.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sys/socket.h>
#include "Client.hpp"
#include "Channel.hpp"

class Server {
    private:
        int                             port;
        std::string                     password;
        int                             master_fd;
	std::vector<struct pollfd>	fds; 
        std::map<int, Client*>           clients;
        std::map<std::string, Channel>  channels;

    public:
        Server(int port, std::string password);
        Server(Server const & other);
        Server& operator=(Server const & other);
        ~Server();
	void run();
        
        int getPort() const;
        std::string getPassword() const;
        int getMasterFd() const;
        std::map<int, Client*> getClients() const;
        std::map<std::string, Channel> getChannels() const;
        
        void setPort(int port);
        void setPassword(const std::string& password);
        void setMasterFd(int fd);
        
        void addClient(int fd, Client* client);
        void removeClient(int fd);
        void addChannel(const std::string& name, const Channel& channel);
        void removeChannel(const std::string& name);
        void processCommand(Client* client, const std::string& command);
        void sendReply(int client_fd, const std::string& reply);
};
#endif
