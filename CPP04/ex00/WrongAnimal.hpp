#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& copy);
		~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& obj);

		std::string getType() const;
		void makeSound() const;
};