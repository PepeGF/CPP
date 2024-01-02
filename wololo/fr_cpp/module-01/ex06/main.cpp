/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:29:33 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/03 09:56:14 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac != 2)
	{
		std::cout << "Error: please use correct syntax: ./HarlFilter [LEVEL]";
		std::cout << "\n";
		return 1;
	}
	harl.complain(std::string(av[1]));
}
