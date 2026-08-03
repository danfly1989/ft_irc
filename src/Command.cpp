/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:47:17 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/03 11:56:44 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Command::Command(bool auth_required) : _auth_required(auth_required)
{
	
}

Command::Command(Command const & other) : _auth_required(other._auth_required)
{

}

Command & Command::operator=(Command const & other)
{
	if(this != &other)
	{
		this->_auth_required = other._auth_required;
	}

	return *this; 
}

Command::~Command()
{

}
