/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:35 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/19 10:18:25 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span test(2);
	try
	{
		test.addNumber(42);
		test.addNumber(43);
		std::cout << test;
		test.addNumber(44);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n\n---ASSIGNMENT TESTS---\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "----------------------\n";

	std::cout << "\n\nTest with 10 000 numbers\n";
	int values[10000];
	for (int i = 0; i < 10000; i++)
		values[i] = i;
	std::vector<int> vect(values, values + sizeof(values) / sizeof(int));
	Span test2(10000);
	test2.addNumberRange(vect.begin(), vect.end());
	//test2.printArray();

	//std::cout << "\n";
	std::cout << test2.shortestSpan() << std::endl;
	std::cout << test2.longestSpan() << std::endl;

	std::cout << "\n\nTry to find shortest span on small arrays\n";
	Span test3(1);
	test3.addNumber(42);
	try
	{
		test3.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n\nTry to overflow the array using another big one\n";
	try
	{
		test3.addNumberRange(vect.begin(), vect.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}
