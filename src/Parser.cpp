/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:34:55 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/27 10:49:35 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Pass.hpp"

Parser::Parser(Server & server) : _server(server)
{	
	//initating the commands map
	_commands["PASS"] = new Pass(true, _server);
}

//naive attempt to loop over commands in destructor.
Parser::~Parser()
{
	std::map<std::string, Command*>::iterator i;
	i = _commands.begin();

	while(i != _commands.end())
	{
		delete i->second;
		++i;
	}
	_commands.clear();
}
