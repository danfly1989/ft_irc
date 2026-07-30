/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwaschwi <zwaschwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:00:18 by zwaschwi          #+#    #+#             */
/*   Updated: 2026/07/07 13:30:57 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>

#define BUFFER_SIZE 1024

class Client {
    private:
        int                         socket_fd;
        std::string                 ip_address;
        std::string                 nickname;
        std::string                 username;
        std::string                 buffer;
        char                        read_buffer[BUFFER_SIZE];
        std::vector<std::string>    channels;
        bool                        is_registered;
        bool                        is_authenticated;

    public:
        Client(int socket_fd, const std::string& ip_address);
        Client(Client const & other);
        Client& operator=(Client const & other);
        ~Client();
        Client();

        int getSocketFd() const;
        std::string getIpAddress() const;
        std::string getNickname() const;
        std::string getUsername() const;
        std::string getBuffer() const;
        char* getReadBuffer();
        std::vector<std::string> getChannels() const;
        bool isRegistered() const;
        bool isAuthenticated() const;
        
        void setNickname(const std::string& nickname);
        void setUsername(const std::string& username);
        void setBuffer(const std::string& buffer);
        void setReadBuffer(const char* buffer, size_t size);
	bool hasCompleteLine() const;
	std::string extractLine();
        void setRegistered(bool registered);
        void setAuthenticated(bool authenticated);
        
        void addChannel(const std::string& channel);
        void removeChannel(const std::string& channel);
        void appendToBuffer(const char* data, size_t size);
    };

#endif
