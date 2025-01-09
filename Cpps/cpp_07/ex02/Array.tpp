/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:57:28 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/09 13:53:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
    std::cout << "Default constructor no array called" << std::endl;
}
template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    _array = new T[_size];
    std::cout << "Size constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : _array(NULL), _size(copy._size)
{
    *this = copy;
    std::cout << "Copy constructor called" << std::endl;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array& other)
{
    
    unsigned int c = 0;

    if (this != &other)
    {
        if (_array != NULL)
            delete[] _array;
        
        this-> _array = new T[other._size];
        this->_size = other._size;
        while (c < _size)
        {
            this->_array[c] = other._array[c];
            c++;
        }
    }
    std::cout << "Equal assignment called" << std::endl;
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int c)
{
	if (c >= this->_size)
	{
		throw OutOfBounds();
	}
	else
		return (this->_array[c]);
}


template<typename T>
unsigned int Array<T>::getSize() const
{
    return (this->_size);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Exception: index out of bounds!";
}

template <typename T>
void Array<T>::fillInt(int value)
{
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = value;
}

template <typename T>
void Array<T>::fillString(const std::string &value)
{
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = value;

}