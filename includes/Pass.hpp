/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 12:06:37 by daflynn           #+#    #+#             */
/*   Updated: 2026/08/07 15:33:29 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASS_HPP
#define PASS_HPP

#include "Command.hpp"

class Pass : public Command
{
	public:
		Pass(bool auth_required, Server & server);
		~Pass();

	virtual void execute(Client*, std::vector<std::string>);
	
};

#endif
