# include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: "  << sp.longestSpan() << std::endl;
	std::cout << std::endl;

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
	int size = 100;
	{
	std::vector<int> random(size);
	std::srand(time(NULL));
	std::generate(random.begin(), random.end(), randomNumber);
	Span big(size);
	big.fillRange(random.begin(), random.end());
	std::cout << "\nBig Span:\n";
	big.printSpan();
	std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
	std::cout << "Longest span: "  << big.longestSpan() << std::endl;
	std::sort(random.begin(), random.end());
	std::cout << "\nOrdered Vector inside Span:\n";
	for (int i = 0; i < size; i++)
		std::cout << random[i] << ", ";
	std::cout << std::endl;
	}
	size = 10000;
	std::vector<int> random(size);
	std::srand(time(NULL));
	std::generate(random.begin(), random.end(), randomNumber);
	Span huge(size);
	huge.fillRange(random.begin(), random.end());
	std::cout << huge.shortestSpan() << std::endl;
	std::cout << huge.longestSpan() << std::endl;
	// huge.printSpan();
	return 0;
}