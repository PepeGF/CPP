# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(std::string type);
	Ice(const Ice& copy);
	~Ice();

	Ice& operator=(const Ice& rhs);

	Ice* clone() const;
	virtual void use(ICharacter & target);
};
