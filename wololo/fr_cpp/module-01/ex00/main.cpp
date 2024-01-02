/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:12:51 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/30 17:09:37 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *foo = newZombie("Foo");
	std::cout << "👉 \033[1;37mFoo has been created. " << std::endl;
	std::cout << "Now we can use announce() function: \033[0m" << std::endl;
	foo->announce();
	randomChump("Bar");
	randomChump("Test Random");
	delete foo;
}
