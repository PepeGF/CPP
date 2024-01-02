/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:20:06 by jcauchet          #+#    #+#             */
/*   Updated: 2022/10/17 19:54:02 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template<typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	Array &operator=(Array const &rhs);
	T &operator[](unsigned int index);
	~Array();
	
	unsigned int const &size() const;
	
	class BadIndex : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Index is not correct or array is NULL";
		}
	};
private:
	T *_array;
	unsigned int _arraySize;
};

// Implementation

template<typename T>
Array<T>::Array()
{
	this->_array = NULL;
	this->_arraySize = 0;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		this->_array[i] = 0;
	this->_arraySize = n;
}

template<typename T> // copy constructor
Array<T>::Array(Array const &src)
{
	if (src._array)
	{
		this->_array = new T[src._arraySize];
		for (unsigned int i = 0; i < src._arraySize; i++)
			this->_array[i] = src._array[i];
	}
	else
		this->_array = NULL;
	this->_arraySize = src._arraySize;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		if (this->_array && rhs._array)
			for (unsigned int i = 0; i < this->_arraySize; i++)
				this->_array[i] = rhs._array[i];
		this->_arraySize = rhs._arraySize;
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned index)
{
	if (!this->_array)
		throw BadIndex();
	if (index > this->_arraySize - 1)
		throw BadIndex();
	else
		return this->_array[index];
}

template<typename T>
unsigned int	const &Array<T>::size() const
{
	return this->_arraySize;
}

template<typename T>
Array<T>::~Array()
{
	if (this->_array)
		delete [] this->_array;
}
