#pragma once

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	
public:
	MutantStack();
	MutantStack(MutantStack const &ref);
	~MutantStack();
	MutantStack &operator=(MutantStack const &copy);

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

	iterator				begin();
	iterator				end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_iterator			begin() const;
	const_iterator			end() const;
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"
