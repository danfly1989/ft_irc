/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 14:50:59 by daflynn           #+#    #+#             */
/*   Updated: 2026/07/07 13:20:49 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ServerException.hpp"
#include "Server.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		std::cerr << "Usage: ./ircserv <port> <password>" <<std::endl;
		return 1;
	}
	try{
		Server server(atoi(argv[1]), argv[2]);
		server.run();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0; 
}
