#include <iostream>
#include <exception>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_range;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int range);
	Bureaucrat(const Bureaucrat& copy);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const & rhs);

	std::string getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);

	class GradeTooHighException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};

	class GradeTooLowException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const & bureaucrat);
