# include "MutantStack.hpp"
# include <list>

int main()
{
	{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Mutant stack last value: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Mutant stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Mutant stack Iterator value: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	}
	{
	std::cout << "\nLists test:\n";
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Last value: " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "List size: " << mstack.size() << std::endl;
	std::cout << "Last value: " << mstack.back() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "List iterator value: " << *it << std::endl;
		++it;
	}
	}
	return 0;
}