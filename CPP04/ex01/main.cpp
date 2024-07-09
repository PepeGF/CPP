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
	std::cout << "Garfield is thinking: " << garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << "Azrael is thinking: " << azrael->getBrain()->getIdea(0) << std::endl;
	azrael->getBrain()->setIdeas("I hate Pitufos");
	std::cout << "Azrael has no good ideas..." << std::endl;

	std::cout << "Garfield is thinking: " << garfield->getBrain()->getIdea(0) << std::endl;
	std::cout << "Azrael is thinking: " << azrael->getBrain()->getIdea(0) << std::endl << std::endl;
	std::cout << "Garfield's brain address: " << garfield->getBrain() << std::endl;
	std::cout << "Azrael's brain address: " << azrael->getBrain() << "\n" <<  std::endl;

	odie->getBrain()->setIdeas("Garfield is my friend");
	const Dog* scoobydoo = new Dog(*odie);

	std::cout << std::endl;
	std::cout << "Odie is thinking: " << odie->getBrain()->getIdea(0) << std::endl;
	std::cout << "ScoobyDoo is thinking: " << scoobydoo->getBrain()->getIdea(0) << std::endl;
	std::cout << "ScoobyDoo feels fear..." << std::endl;
	scoobydoo->getBrain()->setIdeas("We should run away, Shaggy!");

	std::cout << odie->getBrain()->getIdea(0) << std::endl;
	std::cout << scoobydoo->getBrain()->getIdea(0) << std::endl << std::endl;

	std::cout << "Odie's brain address: " << odie->getBrain() << std::endl;
	std::cout << "ScoobyDoo's brain address: " << scoobydoo->getBrain() << std::endl;
	std::cout << std::endl;
	

	
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