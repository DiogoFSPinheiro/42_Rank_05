/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 10:06:24 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
    //std::cout << "MutantStack Default Constructor Called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    //std::cout << "MutantStack Copy Constructor Called" << std::endl;
    *this = copy;
}
template <typename T>
MutantStack<T>::~MutantStack()
{
    //std::cout << "MutantStack Destructor Called" << std::endl;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    //std::cout << "MutantStack Assignment Operator Called" << std::endl;
    if (this != &other)
	{
    	std::stack<T>::operator=(other);
	}
	return *this;
}
