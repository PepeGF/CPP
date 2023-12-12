# include "Floor.hpp"

Floor::Floor()
{
	this->removed = NULL;
	this->next = NULL;
}

Floor::Floor(AMateria* materia)
{
	this->removed = materia;
	this->next = NULL;
}

Floor::Floor(Floor & const copy)
{
	Floor* tmp = &copy;

	while (tmp != NULL)
	{
		this->removed = tmp->removed;
		this->next = tmp->next;
		tmp = tmp->next;
	}
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

void Floor::insert(Floor* newFloor)
{
	this->next = newFloor;
}