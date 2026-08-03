/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 11:12:09 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/03 11:57:10 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Client.hpp"

class Command{
	private:
		bool _auth_required;
	
	public:
		//empty state constructor makes no sense here
		//all commands should call Command from their
		//respective init lists
		Command(bool auth_required);
		Command(Command const & obj);
		Command& operator=(Command const & obj);
		virtual ~Command();

		//the entire point of a command is to be executed => interface
		virtual void	execute(Client*, std::vector<std::string>) = 0;
		bool	auth_required () const;

};

#endif
