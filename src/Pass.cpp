/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:33:46 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/07 16:15:44 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pass.hpp"
#include "Command.hpp"
#include "Server.hpp"

Pass::Pass(bool auth_required, Server & server) : Command(auth_required, server){
	
}

Pass::~Pass(){}

void Pass::execute(Client* client, std::vector<std::string> params)
{

	if (client->isAuthenticated())
	{
		_server.sendReply(client->getSocketFd(), "462: You may not reregister");
		return;
	}
	if(params[0] == _server.getPassword())
	{
		client->setAuthenticated(true);
		_server.sendReply(client->getSocketFd(), "Password accepted");
	}
	else
	{
		_server.sendReply(client->getSocketFd(), "464 : Password incorrect");
	}
}
