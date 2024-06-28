#pragma once

# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <iomanip>

void	print_exchange(std::string input_file);
void	create_database(std::map<std::string, float> &database);
void	open_file(std::ifstream &file);
void	fill_database(std::map<std::string, float> &database, std::ifstream &file);
float	string_to_float(const std::string &str);
void	print_database(std::map<std::string, float> &database);

void    check_and_print_input_line(std::string line);
