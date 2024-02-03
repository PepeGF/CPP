# include "Span.hpp"

Span::Span() : _maxLen(0)
{}

Span::Span(unsigned int len) : _maxLen(len)
{}

Span::Span(const Span& ref) : _arr(ref._arr), _maxLen(ref._maxLen)
{
	*this = ref;
}

Span::~Span()
{}

Span& Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_maxLen = rhs._maxLen;
		for (size_t i = 0; i < rhs._arr.size(); i++)
		{
			this->_arr[i] = rhs._arr[i];
		}
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (this->_arr.size() == this->_maxLen)
		throw maxSizeReachedException();
	this->_arr.push_back(num);
}

int Span::shortestSpan()
{
	if (this->_arr.size() < 2)
		throw insufficientSizeException();
	
	std::vector<int> copy(this->_arr);
	std::sort(copy.begin(), copy.end());
	int diff = std::abs(copy[0] - copy[1]);
	int aux;
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end() - 1; ++it)
	{
		aux = std::abs(*(it + 1) - *it);
		if(aux < diff)
			diff = aux;
	}
	return diff;
}
/* 
	int minimum = std::abs(this->_arr[0] - this->_arr[1]);
	int aux;
	size_t len = this->_arr.size();

	for (size_t i = 0; i < len; i++)
	{
		for (size_t j = 0; j < len; j++)
		{
			if (i == j)
				continue;
			aux = std::abs(this->_arr[i] - this->_arr[j]);
			if ( aux < minimum)
				minimum = aux;
		}
	}
	return minimum; */

int Span::longestSpan()
{
	if (this->_arr.size() < 2)
		throw insufficientSizeException();

	std::vector<int>::iterator max_it = std::max_element(this->_arr.begin(), this->_arr.end());
	std::vector<int>::iterator min_it = std::min_element(this->_arr.begin(), this->_arr.end());
	return (*max_it - *min_it);
}

void Span::fillRange(std::vector<int>::const_iterator it_begin,
					std::vector<int>::const_iterator it_end)
{
	for (std::vector<int>::const_iterator it = it_begin; it != it_end; ++it)
	{
		this->_arr.push_back(*it);
	}
	if (this->_arr.size() > this->_maxLen)
		throw Span::maxSizeReachedException();
}

void Span::printSpan()
{
	size_t size = this->_arr.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		std::cout << this->_arr[i] << ", ";
	}
	std::cout << this->_arr[size - 1] << std::endl;
}

const char* Span::maxSizeReachedException::what(void) const throw()
{
	return ("Unable to add more elements");
}

const char* Span::insufficientSizeException::what(void) const throw()
{
	return ("Operation not permitted, not enought elements");
}

int randomNumber()
{
	return (std::rand() % 1000000);
}