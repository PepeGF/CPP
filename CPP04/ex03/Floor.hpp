# pragma once
# include "AMateria.hpp"

class Floor
{
	private:
		// AMateria* removed[50];
		AMateria* removed;
		
	public:
		Floor();
		Floor(AMateria* materia);
		Floor(const Floor & copy);
		virtual ~Floor();

		Floor& operator=(const Floor& rhs);
		void insert(AMateria* materia);
		void print() const;
};