/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:44:16 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/12 13:17:52 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal *animals[10];

	for (int i = 0; i < 5; i++)
	{
		std::cout << "---------------------" << std::endl;	
		animals[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;	
		animals[i] = new Cat();
	}

	std::cout << std::endl;
	
	for (int i = 0; i < 10; i++)
		std::cout << animals[i]->getType() << std::endl;
	
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "---------------------" << std::endl;	
		delete animals[i];
	}
	return 0;
}
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;
	// delete i;
