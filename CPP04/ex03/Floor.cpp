# include "Floor.hpp"

Floor::Floor() : removed(NULL), next(NULL)
{}

Floor::Floor(AMateria* materia)
{
	this->removed = materia;
	this->next = NULL;
}

Floor::Floor(const Floor & copy)
{
	this->removed = copy.removed;
	this->next = copy.next;
		
}

Floor::~Floor()
{
	Floor* aux = this;
	while (aux)
	{
		delete aux->removed;
		aux = aux->next;
	}
}

void Floor::insert(AMateria* materia)
{
	if (materia)
	{
		this->removed = materia;
		Floor* newFloor = new Floor(materia);
		newFloor->next = this->next;
		this->next = newFloor;
	}
}