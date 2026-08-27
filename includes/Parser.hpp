/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 18:14:04 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/27 09:50:38 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Command.hpp"
#include <map>

class Server;

class Parser{
	private:
		Server & _server;
		//each command shall be an element of the _commands map
		std::map<std::string, Command*> _commands;
		Parser(Parser const & other);
		Parser & operator=(Parser const & other);

	public:
		Parser(Server & server);
		~Parser();
		void invoke(Client * client, const std::string & line);

};

#endif
