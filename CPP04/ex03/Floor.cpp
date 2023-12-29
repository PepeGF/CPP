# include "Floor.hpp"

Floor::Floor() : removed(NULL)
{}

Floor::Floor(AMateria* materia)
{
	this->removed = materia ? materia->clone() : NULL;
}

Floor::Floor(const Floor & copy)
{
	this->removed = copy.removed ? copy.removed->clone() : NULL;
}

Floor::~Floor()
{
	Floor* aux = this;
	// while (aux)
	// {
	// 	delete aux->removed;
	// 	delete aux;
	// }
}

void Floor::insert(AMateria* materia)
{
	if (materia)
	{

		Floor* newNode = new Floor(materia);
	}
}

void Floor::print() const
{
	std::cout << this->removed->getType() << std::endl;
}
