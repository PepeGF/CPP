#pragma once

# include "Automata.hpp"
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <iomanip>

# define INDEX_INI 0
# define LEN_DATE_STRING 10
# define FIRST_MINUS_INDEX 4
# define SECOND_MINUS_INDEX 7
# define YEAR_INI_INDEX 0
# define YEAR_LEN 4
# define MONTH_INI_INDEX 5
# define MONTH_LEN 2
# define DAY_INI_INDEX 8
# define DAY_LEN 2
# define SEPARATOR_INI_INDEX 10
# define SEPARATOR_LEN 3
# define VALUE_INI_INDEX 13

void	print_exchange(std::string input_file);
void	create_database(std::map<std::string, float> &database);
void	open_file(std::ifstream &file);
void	fill_database(std::map<std::string, float> &database, std::ifstream &file);
float	string_to_float(const std::string &str);
void	print_database(std::map<std::string, float> &database);

void    check_and_print_input_line(std::string &line);
void    validate_date(std::string &line);
void    validate_separator(std::string &line);
void    validate_value(std::string &line);
