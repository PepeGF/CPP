# include "Animal.hpp"
# include "WrongAnimal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongCat.hpp"


int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* pikachu = new WrongCat();
	const WrongCat* doraemon = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	pikachu->makeSound();
	doraemon->makeSound();
	
	std::cout << std::endl;
	
	delete meta;
	delete j;
	delete i;
	delete pikachu;
	delete doraemon;
	return 0;
}
