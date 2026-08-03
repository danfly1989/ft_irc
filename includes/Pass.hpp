/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:06:37 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/03 12:25:15 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASS_HPP
#define PASS_HPP

#include "Command.hpp"

class Pass : public Command
{
	public:
		Pass();
		Pass(Pass const & other);
		Pass & operator=(Pass const & other);
		~Pass();

	virtual void execute(Client*, std::vector<std::string>);
	
};

#endif
