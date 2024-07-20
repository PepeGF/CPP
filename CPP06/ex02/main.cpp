#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <iostream>

Base * generate(void)
{
	std::srand(std::time(NULL));

	int num = std::rand() % 3;
	std::cout << "Random number: " << num << std::endl;
	Base *ptr;

	switch (num)
	{
	case 0:
		ptr = new A;
		std::cout << "Type A pointer generated" << std::endl;
		break;
	case 1:
		ptr = new B;
		std::cout << "Type B pointer generated" << std::endl;
		break;
	case 2:
		ptr = new C;
		std::cout << "Type C pointer generated" << std::endl;
		break;
	}
	return ptr;
}

void identify(Base *p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "It's A type pointer" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "It's B type pointer" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "It's C type pointer" << std::endl;
		return ;
	}
	std::cout << "It's neither A, B nor C pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's A type reference" << std::endl;
		return ;
	}
	catch (...){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It's B type reference" << std::endl;
		return ;
	}
	catch (...){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It's C type reference" << std::endl;
		return ;
	}
	catch (...){}
}

int main()
{
	Base* ptr = generate();
	identify(ptr);
	Base& other = *ptr;
	identify(other);
	return (0);
}