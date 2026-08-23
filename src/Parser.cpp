/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 18:34:55 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/23 18:37:30 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Pass.hpp"

Parser::Parser(Server & server) : _server(server)
{
	_commands["PASS"] = new Pass(true, _server);
}
