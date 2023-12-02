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

	const WrongAnimal pokemon("Pikachu");
	const WrongCat doraemon("Doraemon");

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	pokemon.makeSound();
	doraemon.makeSound();
	
	delete meta;
	delete j;
	delete i;
	return 0;


/* 
	Animal bicho;
	Animal perro("perro");
	Animal lobo(perro);
	
	return (0); */
}