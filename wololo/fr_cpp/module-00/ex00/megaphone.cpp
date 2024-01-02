/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:18:18 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/27 18:09:47 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

int main(int ac, char **av)
{
	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}
	for (int i = 1; i < ac; i++)
	{
		string str = av[i];
		for (int j = 0; str[j]; j++)
			cout << char(toupper(str[j]));
		cout << " ";
	}
	cout << endl;
}
