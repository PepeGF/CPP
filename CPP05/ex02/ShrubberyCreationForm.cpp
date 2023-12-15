# include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("Shrubbery", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : 
AForm(copy), _target(copy._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	std::string name = _target + "_shrubbery";
	return (name);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	if (this->getSigned() == false)
		throw AForm::GradeTooLowException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

	std::ofstream file((this->getTarget()).c_str());
	if ( file.is_open() == false)
		std::cerr << "Unable to open " << this->getTarget() << std::endl;
	else
	{
        file << "                                                     .        " << std::endl; 
        file << "                                          .         ;         " << std::endl; 
        file << "             .              .              ;%     ;;          " << std::endl; 
        file << "               ,           ,                :;%  %;           " << std::endl; 
        file << "                :         ;                   :;%;'     .,    " << std::endl; 
        file << "       ,.        %;     %;            ;        %;'    ,;      " << std::endl; 
        file << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'       " << std::endl; 
        file << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'        " << std::endl; 
        file << "           ;%;      %;        ;%;        % ;%;  ,%;'          " << std::endl; 
        file << "            `%;.     ;%;     %;'         `;%%;.%;'            " << std::endl; 
        file << "             `:;%.    ;%%. %@;        %; ;@%;%'               " << std::endl; 
        file << "                `:%;.  :;bd%;          %;@%;'                 " << std::endl; 
        file << "                  `@%:.  :;%.         ;@@%;'                  " << std::endl; 
        file << "                    `@%.  `;@%.      ;@@%;                    " << std::endl; 
        file << "                      `@%%. `@%%    ;@@%;                     " << std::endl; 
        file << "                        ;@%. :@%%  %@@%;                      " << std::endl; 
        file << "                          %@bd%%%bd%%:;                       " << std::endl; 
        file << "                            #@%%%%%:;;                        " << std::endl; 
        file << "                            %@@%%%::;                         " << std::endl; 
        file << "                            %@@@%(o);  . '                    " << std::endl; 
        file << "                            %@@@o%;:(.,'                      " << std::endl; 
        file << "                        `.. %@@@o%::;                         " << std::endl; 
        file << "                           `)@@@o%::;                         " << std::endl; 
        file << "                            %@@(o)::;                         " << std::endl; 
        file << "                           .%@@@@%::;                         " << std::endl; 
        file << "                           ;%@@@@%::;.                        " << std::endl; 
        file << "                          ;%@@@@%%:;;;.                       " << std::endl; 
        file << "                      ...;%@@@@@%%:;;;;,..                    " << std::endl; 

        file.close();
	}

}