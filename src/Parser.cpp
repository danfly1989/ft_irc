/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:34:55 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/27 12:14:24 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Pass.hpp"
#include <sstream>
#include <vector>

Parser::Parser(Server & server) : _server(server)
{	
	//initating the commands map
	_commands["PASS"] = new Pass(false, _server);
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

void	Parser::invoke(Client * client, const std::string & line)
{
	(void) client;
	std::istringstream iss(line);
	std::string word;
	std::vector<std::string> tokens;
	while(iss >> word)
	{
		tokens.push_back(word);
	}
}
