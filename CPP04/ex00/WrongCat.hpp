# pragma once

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string const type);
		WrongCat(const WrongCat& copy);
		~WrongCat();

		WrongCat& operator=(const WrongCat& obj);

		void makeSound() const;
};