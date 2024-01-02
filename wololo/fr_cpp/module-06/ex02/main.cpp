/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:41:56 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/16 19:22:54by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate()	
{
	srand((unsigned int)time(NULL));
	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return dynamic_cast<Base *>(new A());
			break;
		case 1:
			return dynamic_cast<Base *>(new B());
			break;
		default:
			return dynamic_cast<Base *>(new C());
			break;
	}
}

void	identify(Base *p)
{
	A *ptrA = dynamic_cast<A *>(p);
	if (ptrA)
	{
		std::cout << "The real type of this base class is A.\n";
		return ;
	}
	B *ptrB = dynamic_cast<B *>(p);
	if (ptrB)
	{
		std::cout << "The real type of this base class is B.\n";
		return ;
	}
	C *ptrC = dynamic_cast<C *>(p);
	if (ptrC)
	{
		std::cout << "The real type of this base class is C.\n";
		return ;
	}
	std::cout << "This class doesn't match any subclasses!\n";
}

void	identify(Base &p)
{
	try
	{
		A &ref = dynamic_cast<A &>(p);
		(void)ref;
		std::cout << "The real type of this base class is A.\n";
	}
	catch (std::bad_cast &e)
	{
		try
		{
			B &ref = dynamic_cast<B &>(p);
			(void)ref;
			std::cout << "The real type of this base class is B.\n";
		}
		catch (std::bad_cast &e)
		{
			try
			{
				C &ref = dynamic_cast<C &>(p);
				(void)ref;
				std::cout << "The real type of this base class is C.\n";
			}
			catch (std::bad_cast &e)
			{
				std::cout << "This class doesn't match any subclasses!\n";
			}
		}
	}
}


int main()
{
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;

	std::cout << std::endl;

	// Error handling
	int *null_test = NULL;
	identify(NULL);
	Base null_base = *reinterpret_cast<Base *>(null_test);
	identify(null_base);
}
