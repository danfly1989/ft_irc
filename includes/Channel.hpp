/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwaschwi <zwaschwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 15:26:59 by zwaschwi          #+#    #+#             */
/*   Updated: 2026/06/25 15:05:11 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Client.hpp"

#define MODE_INVITE_ONLY (1 << 0)
#define MODE_TOPIC (1 << 1)
#define MODE_KEY (1 << 2)
#define MODE_USER_LIMIT (1 << 3)
#define OPERATOR_PRIVELEGE 'o'


class Channel {
    private:
        std::string name;
        std::string topic;
        std::string key;
        std::vector<Client*> users;
        std::vector<Client*> operators;
        int         user_limit;
        bool        invite_only;
        bool        topic_restricted;
	unsigned char		mode;
        
    public:
        Channel(std::string name);
        Channel(Channel const & other);
        Channel& operator=(Channel const & other);
        ~Channel();
        
        std::string getName();
        std::string getTopic();
        std::string getKey();
        std::vector<Client*> getUsers();
        std::vector<Client*> getOperators();
        int getUserLimit();
        bool isInviteOnly();
        bool isTopicRestricted();
	std::string getMode() const;
        void setTopic(std::string topic);
        void setKey(std::string key);
        void setUserLimit(int limit);
        void setInviteOnly(bool invite_only);
        void setTopicRestricted(bool topic_restricted);
        void addUser(Client* user);
        void removeUser(Client* user);
        void addOperator(Client* user);
        void removeOperator(Client* user);
        
};
#endif
