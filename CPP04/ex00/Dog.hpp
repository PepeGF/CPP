# pragma once

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string const type);
		Dog(const Dog& copy);
		virtual ~Dog();

		Dog& operator=(const Dog& obj);

		void makeSound() const;
};