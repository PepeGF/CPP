# pragma once

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		virtual ~Dog();

		Dog& operator=(const Dog& obj);

		virtual void makeSound() const;
}