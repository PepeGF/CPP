/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:48:03 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/18 13:51:48 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int values[5] = {42, 43, 44, 45, 46};

	// Testing with vectors
	std::cout << "Vectors:\n";
	std::vector<int> vect(values, values + sizeof(values) / sizeof(int));
	easyfind(vect, 42) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(vect, -10) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(vect, 46) ? std::cout << "Yes\n" : std::cout << "No\n";

	
	std::cout << "\n\nLists:\n";
	std::list<int> list(values, values + sizeof(values) / sizeof(int));
	easyfind(list, 42) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(list, -10) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(list, 46) ? std::cout << "Yes\n" : std::cout << "No\n";
	std::cout << "Last element of the list is removed:\n";
	list.pop_back();
	easyfind(list, 46) ? std::cout << "Yes\n" : std::cout << "No\n";
	list.push_back(46);
	std::cout << "Then it comes back:\n";
	easyfind(list, 46) ? std::cout << "Yes\n" : std::cout << "No\n";

	std::cout << "\n\nDeque:\n";
	std::deque<int> deque(values, values + sizeof(values) / sizeof(int));
	easyfind(deque, 44) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(deque, 43243) ? std::cout << "Yes\n" : std::cout << "No\n";
	easyfind(deque, 41) ? std::cout << "Yes\n" : std::cout << "No\n";
}
