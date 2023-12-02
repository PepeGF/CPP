# pragma once

# include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain* Brain;
	public:
		Cat();
		Cat(std::string const type);
		Cat(const Cat& copy);
		virtual ~Cat();

		Cat& operator=(const Cat& obj);

		void makeSound() const;
};