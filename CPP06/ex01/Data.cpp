# include "Data.hpp"

std::ostream& operator<<(std::ostream& os, Data const & data)
{
	os << "Data address: " << &data << "\nData content: " << data.num;
	return os;
}