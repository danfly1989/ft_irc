/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:47:17 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/07 11:04:07 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(bool auth_required, Server & server) : _auth_required(auth_required), _server(server)
{
	
}

Command::Command(Command const & other) : _auth_required(other._auth_required), _server(other._server)
{

}


Command::~Command()
{

}
