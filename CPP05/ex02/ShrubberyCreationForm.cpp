# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}