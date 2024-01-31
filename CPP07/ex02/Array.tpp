#pragma once

template<typename T>
Array<T>::Array()
{
	this->_ptr = NULL;
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	this->_ptr = new T[size];
	for (int i = 0; i < static_cast<int>(size); i++)
		this->_ptr[i] = 0;		
}

template<typename T>
Array<T>::Array(Array const &copy)
{
	if (copy._ptr)
	{
		this->_size = copy._size;
		this->_ptr = new T[copy._size];
		for (int i = 0; static_cast<int>(copy._size); i++)
			this->_ptr[i] = copy._ptr[i];
	}
	else
	{
		this->_ptr = NULL;
		this->_size = copy._size;
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] _ptr;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs && this->_ptr && rhs._ptr)
	{
		for (int i = 0; i < static_cast<int>(this->_size); i++)
			this->_ptr[i] = rhs._ptr[i];
		this->_size = rhs._size;
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size || !this->_ptr)
		throw (std::out_of_range("Index out of range"));
	else
		return (this->_ptr[index]);	
}

template<typename T>
unsigned int const &Array<T>::size() const
{
	return (this->_size);
}
