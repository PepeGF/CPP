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

	Fixed& operator=(const Fixed &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

};
