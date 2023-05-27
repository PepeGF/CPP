#include <iostream>

class Fixed
{
private:

	int	_value;
	static const int _bits = 8;

public:

	Fixed();
	Fixed(const Fixed& source);
	~Fixed();

	int		Fixed::getRawBits(void) const;
	void	Fixed::setRawBits(int const raw);

};
