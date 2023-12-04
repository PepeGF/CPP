# pragma once

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* _brain;
		
	public:
		Cat();
		Cat(std::string const type);
		Cat(const Cat& copy);
		virtual ~Cat();

		Cat& operator=(const Cat& obj);

		void makeSound(void) const;
		Brain* getBrain(void) const;
};