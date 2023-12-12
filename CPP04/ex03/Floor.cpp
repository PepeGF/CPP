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

void Floor::insert(Floor* newFloor)
{
<<<<<<< HEAD
	this->next = newFloor;
=======
	if (materia)
	{
		Floor* newFloor = new Floor(materia);
		newFloor->next = this->next;
		this->next = newFloor;
	}
>>>>>>> 714603cd136417b6f83be8e93f3501a95ebe5f90
}