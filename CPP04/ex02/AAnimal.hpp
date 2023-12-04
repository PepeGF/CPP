#pragma once

#include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& copy);
		virtual ~AAnimal();

		AAnimal& operator=(const AAnimal& obj);

		std::string getType() const;
		virtual void makeSound() const = 0;
};