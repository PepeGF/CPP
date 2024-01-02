/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:38:36 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/16 16:33:51 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

typedef std::numeric_limits<double> double_max;
typedef std::numeric_limits<float> float_max;

#define ASCII_TYPE 42
#define FLOAT_TYPE 43
#define DOUBLE_TYPE 44
#define SPECIAL_CASES 45

void	special_cases_handling(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
		std::cout << "float: nanf" << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "float: -inff" << std::endl;
	else
		std::cout << "float: inff" << std::endl;
	if (str == "nan" || str == "nanf")
		std::cout << "double: nan" << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "float: -inf" << std::endl;
	else
		std::cout << "float: inf" << std::endl;
}

void	ascii_handling(std::string str)
{
	if ((str[0] < 48 || str[0] > 57) && !str[1])
	{
		if (str[0] < 32 || str[0] > 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(str[0]) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double " << static_cast<double>(str[0]) << std::endl;
	}
	else
	{
		int value = std::stoi(str);
		if (value < 32 || value > 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(1) << "double " << static_cast<double>(value) << std::endl;
	}	
}

void	float_handling(float value, std::string str)
{
	try
	{
		std::stoi(str);
		if (value < 32 || value > 127)
		std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	int i; int j = 0;
	for (i = 0; str[i]; i++)
		if (str[i] == '.')
			break;
	for (i++; str[i]; i++)
		j++;
	if (j > float_max::max_digits10)
		std::cout << std::fixed << std::setprecision(float_max::max_digits10) << "float: " << value << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(j - 1) << "float: " << value << "f" << std::endl;
	if (j > double_max::max_digits10)
		std::cout << std::fixed << std::setprecision(double_max::max_digits10) << "double: " << static_cast<double>(value) << std::endl;
	else
		std::cout << std::fixed << std::setprecision(j - 1) << "double: " << static_cast<double>(value) << std::endl;
}

void	double_handling(double value, std::string str)
{
	try
	{
		std::stoi(str);
		if (value < 32 || value > 127)
		std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	int i; int j = 0;
	for (i = 0; str[i]; i++)
		if (str[i] == '.')
			break;
	for (i++; str[i]; i++)
		j++;
	if (j > float_max::max_digits10)
		std::cout << std::fixed << std::setprecision(float_max::max_digits10) << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(j) << "float: " << static_cast<float>(value) << "f" << std::endl;
	if (j > double_max::max_digits10)
		std::cout << std::fixed << std::setprecision(double_max::max_digits10) << "double: " << value << std::endl;
	else
		std::cout << std::fixed << std::setprecision(j) << "double: " << value << std::endl;
}

int	check_type(std::string str)
{
	std::string special_cases[8] = {"+inf", "-inf", "inf", "+inff", "-inff", "inff", "nan", "nanf"};

	for (int i = 0; i < 8; i++)
		if (str == special_cases[i])
			return SPECIAL_CASES;
	int f = 0; int d = 0; int b = 0; int i = -1;
	if (str[0] == '-')
		i++;
	if (!i && !str[1])
		return ASCII_TYPE;
	if (!i && (str[1] > 57 || str[1] < 48))
		throw std::exception();
	while (str[++i])
	{
		if (str[i] == '.' && str[i + 1] == 'f')
		throw std::exception();
		if (str[i] == '.')
			d++;
		else if (str[i] == 'f')
			f++;
		else if (str[i] < 48 || str[i] > 57)
			b++;
	}
	if (str.length() > 1)
	{
		if (str[i - 1] == '.')
			throw std::exception();
		if (b || f > 1 || d > 1)
			throw std::exception();
		else if (d && f)
			return FLOAT_TYPE;
		else if (f)
			throw std::exception();
		else if (d)
			return DOUBLE_TYPE;	
		std::stoi(str);
	}
	return ASCII_TYPE;	
	
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please use a correct command format: ./convert [Number]\n";
		return 1;
	}
	std::string str = static_cast<std::string>(av[1]);
	int	type;
	try
	{
		type = check_type(str);
	}
	catch (std::exception &e)
	{
		std::cout << "Please use a correct number format\n";
		return 1;
	}
	switch (type)
	{
		case SPECIAL_CASES:
			special_cases_handling(str);
			break;
		case FLOAT_TYPE:
			float_handling(std::stof(str), str);
			break;
		case DOUBLE_TYPE:
			double_handling(std::stod(str), str);
			break;
		case ASCII_TYPE:
			ascii_handling(str);
			break;
	}
	return 0;
}
