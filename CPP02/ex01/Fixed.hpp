#include <iostream>
#include <cmath>

class Fixed
{
private:

	int	_value;
	static const int _bits = 8;

public:

	Fixed();
	Fixed(const Fixed& source);
	Fixed(int const integer);
	Fixed(float const decimal);
	~Fixed();

	Fixed& operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

};
