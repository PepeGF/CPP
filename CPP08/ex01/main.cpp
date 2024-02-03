# include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try	{
		sp.addNumber(42);
	}
	catch (const Span::maxSizeReachedException& e)	{
		std::cerr << e.what() << std::endl;
	}
	Span other(1);
	other.addNumber(42);
	try	{
		other.shortestSpan();
	}
	catch(const Span::insufficientSizeException& e)	{
		std::cerr << e.what() << std::endl;
	}
	try	{
		other.longestSpan();
	}
	catch(const Span::insufficientSizeException& e)	{
		std::cerr << e.what() << std::endl;
	}

	Span huge(100000);
	for (int i = 0; i < 100000; i++)
		huge.addNumber(i);
	std::cout << huge.shortestSpan() << std::endl;
	std::cout << huge.longestSpan() << std::endl;
	
	return 0;
}