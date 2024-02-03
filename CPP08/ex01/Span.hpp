# pragma once
# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>
# include <ctime>

class Span
{
private:
	std::vector<int>	_arr;
	unsigned int		_maxLen;
	Span();
public:
	Span(unsigned int len);
	Span(const Span &ref);
	~Span();

	Span& operator=(const Span &rhs);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();

	void printSpan();
	void fillRange(std::vector<int>::const_iterator it_begin,
					std::vector<int>::const_iterator it_end);
	class maxSizeReachedException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};
	
	class insufficientSizeException : virtual public std::exception
	{
		public:
			const char* what() const throw ();
	};
};

int randomNumber();
