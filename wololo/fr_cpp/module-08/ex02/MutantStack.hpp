/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:33:21 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/19 10:29:39 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack();
	MutantStack(MutantStack<T, Container> const &src);
	MutantStack<T, Container> &operator=(MutantStack<T, Container> const &rhs);
	~MutantStack();
	
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	typedef typename Container::value_type value_type;
	typedef typename Container::size_type size_type;
	typedef typename Container::reference reference;
	typedef typename Container::const_reference const_reference;

	iterator begin() {return this->c.begin();};
	reverse_iterator rbegin() {return this->c.rbegin();};
	const_iterator cbegin() {return this->c.cbegin();};
	const_reverse_iterator crbegin() {return this->c.crbegin();};
	iterator end() {return this->c.end();};
	reverse_iterator rend() {return this->c.rend();};
	const_iterator cend() {return this->c.cend();};
	const_reverse_iterator crend() {return this->c.crend();};
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &src)
{
	*this = src;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(MutantStack<T, Container> const &rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}
