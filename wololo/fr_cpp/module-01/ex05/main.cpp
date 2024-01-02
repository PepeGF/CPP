/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:29:33 by juliencauch       #+#    #+#             */
/*   Updated: 2022/10/03 09:54:33 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("DEBUG");
	std::cout << "----------------------------------" << std::endl;
	harl.complain("INFO");
	std::cout << "----------------------------------" << std::endl;
	harl.complain("WARNING");
	std::cout << "----------------------------------" << std::endl;
	harl.complain("ERROR");
	std::cout << "----------------------------------" << std::endl;
	harl.complain("BULLSHIT");
}
