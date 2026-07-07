/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwaschwi <zwaschwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:41:24 by zwaschwi          #+#    #+#             */
/*   Updated: 2026/06/25 15:06:02 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

    Channel::Channel(std::string name)
    {
        this->name = name;
        this->topic = "";
        this->key = "";
        this->user_limit = 0;
        this->invite_only = false;
        this->topic_restricted = false;
        this->mode = 0;
        this->users = std::vector<Client*>();
        this->operators = std::vector<Client*>();
    }
    
    Channel::Channel(Channel const &other)
    {
        this->name = other.name;
        this->topic = other.topic;
        this->key = other.key;
        this->users = other.users;
        this->operators = other.operators;
        this->user_limit = other.user_limit;
        this->invite_only = other.invite_only;
        this->topic_restricted = other.topic_restricted;
        this->mode = other.mode;
    }
    
    Channel& Channel::operator=(Channel const & other)
    {
        if(this != &other)
        {
            this->name = other.name;
            this->topic = other.topic;
            this->key = other.key;
            this->users = other.users;
            this->operators = other.operators;
            this->user_limit = other.user_limit;
            this->invite_only = other.invite_only;
            this->topic_restricted = other.topic_restricted;
            this->mode = other.mode;
        }
        return *this;
    }
    

	Channel::~Channel()
    {
    }
        
    std::string Channel::getName()
    {
        return this->name;
    }
    
    std::string Channel::getTopic()
    {
        return this->topic;
    }
    
    std::string Channel::getKey()
    {
        return this->key;
    }
    
    std::vector<Client*> Channel::getUsers()
    {
        return this->users;
    }
    
    std::vector<Client*> Channel::getOperators()
    {
        return this->operators;
    }
    
    int Channel::getUserLimit()
    {
        return this->user_limit;
    }
    
    bool Channel::isInviteOnly()
    {
        return this->invite_only;
    }
    
    bool Channel::isTopicRestricted()
    {
        return this->topic_restricted;
    }
    
std::string Channel::getMode() const
    {
	    std::string m = "+";
	    if(mode & MODE_INVITE_ONLY) m += 'i';
	    if(mode &  MODE_TOPIC) m += 't';
	    if(mode & MODE_KEY) m += 'k';
	    if(mode & MODE_USER_LIMIT) m+= 'l';
	    if(m == "+") return "";
	    return m;
    }
    
    void Channel::setTopic(std::string topic)
    {
        this->topic = topic;
    }
    
    void Channel::setKey(std::string key)
    {
        this->key = key;
    }
    
    void Channel::setUserLimit(int limit)
    {
        this->user_limit = limit;
    }
    
    void Channel::setInviteOnly(bool invite_only)
    {
        this->invite_only = invite_only;
    }
    
    void Channel::setTopicRestricted(bool topic_restricted)
    {
        this->topic_restricted = topic_restricted;
    }
    
    void Channel::addUser(Client* user)
    {
        this->users.push_back(user);
    }
    
    void Channel::removeUser(Client* user)
    {
        for(std::vector<Client*>::iterator i = this->users.begin(); i != this->users.end(); ++i)
        {
            if(*i == user)
            {
                this->users.erase(i);
                break;
            }
        }
    }
    
    void Channel::addOperator(Client* user)
    {
        this->operators.push_back(user);
    }
    
    void Channel::removeOperator(Client* user)
    {
        for(std::vector<Client*>::iterator i = this->operators.begin(); i != this->operators.end(); ++i)
        {
            if(*i == user)
            {
                this->operators.erase(i);
                break;
            }
        }
    }
