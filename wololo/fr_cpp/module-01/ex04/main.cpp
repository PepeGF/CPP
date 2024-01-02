/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:20:28 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/04 10:39:01 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

void	error_handling(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: incorrect syntax." << std::endl;
		exit(1);
	}
	struct stat path_stat;
    stat(av[1], &path_stat);
    int is_dir =  S_ISDIR(path_stat.st_mode);
	if (is_dir)
	{
		std::cout << "Error: path is a directory." << std::endl;
		exit(1);
	}
	if (!av[2][0])
	{
		std::cout << "Error: pattern to replace cannot be empty." << std::endl;
		exit(1);
	}
}

int main(int ac, char **av)
{
	error_handling(ac, av);
	std::string	input_name(av[1]);
	std::ifstream input(input_name);
	if (!input)
	{
		std::cout << "Error: wrong filename." << std::endl;
		return 1;
	}
	std::string output_name = input_name + ".replace";
	std::ofstream output(output_name);
	while (input)
	{
		std::string line;
		getline(input, line);
		if (!line[0])
			break;
		std::string to_erase = av[2];
		std::string to_insert = av[3];
		std::string sub = line;
		int i = 0;
		while (1)
		{
			int pos = int(line.find(to_erase));
			if (pos < 0)
				break;
			line.erase(pos, to_erase.length());
			sub.erase(pos + i, to_erase.length());
			sub.insert(pos + i, to_insert);
			i += to_insert.length();
		}
		output << sub << "\n";
	}
}
