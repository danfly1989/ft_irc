/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:34:55 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/27 13:16:53 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Pass.hpp"
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

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
	if(tokens.empty())
		return;
	//commands are usually expected to be upper case
	//not enforced by RFC but most common practice
	//It also is more true to that 2000s IRC feel
	std::string upper;
	upper.resize(tokens[0].size());
	std::transform(tokens[0].begin(), tokens[0].end(), upper.begin(), ::toupper);
}
