# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(std::string type);
	Cure(const Cure& copy);
	~Cure();

	Cure& operator=(const Cure& rhs);

	Cure* clone() const;
	void use(ICharacter & target);
};
