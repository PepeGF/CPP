#pragma once

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
# define INVALID_LINE -1
# define LINE_OK 0

void	print_exchange(std::string input_file, std::map<std::string, float> &database);
void	create_database(std::map<std::string, float> &database);
void	open_file(std::ifstream &file);
void	fill_database(std::map<std::string, float> &database, std::ifstream &file);
void	print_database(std::map<std::string, float> &database);

int     check_and_print_input_line(std::string &line);
int     validate_date(std::string &line);
int     validate_date_format(std::string line);
int     validate_separator(std::string &line);
int     validate_value(std::string &line);

int     print_invalid_line(std::string error);
int     print_invalid_date(std::string date);
int     validate_year(std::string date);
int     validate_month(std::string date, std::string line);
int     validate_day(std::string date);
int     validate_real_day(std::string line, std::string date);

void    print_output(std::string date, float input_value, float database_value);
