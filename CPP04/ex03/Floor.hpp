# pragma once
# include "AMateria.hpp"

class Floor
{
	private:
		AMateria* removed;
		Floor* next;
	public:
		Floor();
		Floor(AMateria* materia);
		Floor(Floor & const copy);
		virtual ~Floor();

		Floor& operator=(const Floor& rhs);
		void insert(AMateria* materia);
};