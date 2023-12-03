# pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(std::string const type);
		Dog(const Dog& copy);
		virtual ~Dog();

		Dog& operator=(const Dog& obj);

		void makeSound(void) const;
		Brain* getBrain(void) const;
};