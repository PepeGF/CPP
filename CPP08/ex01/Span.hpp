# pragma once
# include <vector>
# include <iostream>
# include <exception>
# include <algorithm>
# include <cmath>

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
