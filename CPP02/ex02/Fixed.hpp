#include <iostream>
#include <cmath>

class Fixed
{
private:

	int	_value;
	static const int _bits = 8;

public:

	Fixed();
	Fixed(int const integer);
	Fixed(float const decimal);
	Fixed(Fixed const &source);
	~Fixed();

	Fixed& operator=(Fixed const &fix);
	Fixed& operator+(Fixed const &fix);
	Fixed& operator-(Fixed const &fix);
	Fixed& operator*(Fixed const &fix);
	Fixed& operator/(Fixed const &fix);
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	bool operator>(Fixed const &rhs);
	bool operator>=(Fixed const &rhs);
	bool operator<(Fixed const &rhs);
	bool operator<=(Fixed const &rhs);
	bool operator==(Fixed const &rhs);
	bool operator!=(Fixed const &rhs);

	static Fixed const &max(Fixed const &fix1, Fixed const &fix2);
	static Fixed &max(Fixed &fix1, Fixed &fix2);
	static Fixed const &min(Fixed const &fix1, Fixed const &fix2);
	static Fixed &min(Fixed &fix1, Fixed &fix2);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

};

std::ostream& operator<<(std::ostream &os, Fixed const &fix);
