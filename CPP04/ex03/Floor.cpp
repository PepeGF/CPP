# include "Floor.hpp"

Floor::Floor() : removed(NULL), next(NULL)
{}

Floor::Floor(AMateria* materia)
{
	this->removed = materia ? materia->clone() : NULL;
	this->next = NULL;
}

Floor::Floor(const Floor & copy)
{
	this->removed = copy.removed ? copy.removed->clone() : NULL;
	this->next = copy.next;
		
}

Floor::~Floor()
{
	Floor* aux = this;
	while (aux)
	{
		Floor* nextNode = aux->next;
		delete aux->removed;
		delete aux;
		aux = nextNode;
	}
}

void Floor::insert(AMateria* materia)
{
	if (materia)
	{
		Floor* newNode = new Floor(materia->clone());
		newNode->next = this->next;
		this->next = newNode;
		materia = NULL;
	}
}
