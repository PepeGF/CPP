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
	const Cat* garfield = new Cat();
	const Dog* odie = new Dog();

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

	garfield->getBrain()->setIdeas("I hate mondays");
	const Cat* azrael = new Cat(*garfield);
	std::cout << std::endl;
	std::cout << garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << azrael->getBrain()->getIdea(0) << std::endl;
	azrael->getBrain()->setIdeas("I hate Pitufos");

	std::cout << garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << azrael->getBrain()->getIdea(0) << std::endl << std::endl;

	odie->getBrain()->setIdeas("Garfield is my friend");
	const Dog* scoobydoo = new Dog(*odie);

	std::cout << std::endl;
	std::cout << odie->getBrain()->getIdea(0) << std::endl;
	std::cout << scoobydoo->getBrain()->getIdea(0) << std::endl;
	scoobydoo->getBrain()->setIdeas("We should run away, Shaggy!");

	std::cout << odie->getBrain()->getIdea(0) << std::endl;
	std::cout << scoobydoo->getBrain()->getIdea(0) << std::endl << std::endl;
	

	
	delete meta;
	delete j;
	delete i;
	delete pikachu;
	delete doraemon;
	delete garfield;
	delete azrael;
	delete odie;
	delete scoobydoo;
	return 0;
}