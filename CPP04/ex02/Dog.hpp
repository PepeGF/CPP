# pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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