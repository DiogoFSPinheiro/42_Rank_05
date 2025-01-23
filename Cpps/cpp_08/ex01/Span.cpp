/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 19:03:43 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span()
{
    std::cout << "Span Default Constructor Called" << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
	std::cout << "Span Data Constructor Called" << std::endl;
}

Span::Span(const Span &copy)
{
    std::cout << "Span Copy Constructor Called" << std::endl;
    *this = copy;
}
Span::~Span()
{
    std::cout << "Span Destructor Called" << std::endl;
}
Span &Span::operator=(const Span &other)
{
    std::cout << "Span Assignment Operator Called" << std::endl;
    if (this != &other) {
        // Copy assignment operator implementation
    }
    return *this;
}

void Span::addNumber(int n)
{
	if (_container.size() == _size)
		throw NoMoreSpaceException();
	_container.push_back(n);
}

long	Span::longestSpan()
{
	long	max, min;
	
	if (_container.size() < 2)
		throw NotEnoughMembers();
	
	min = *std::min_element(_container.begin(), _container.end());
	max = *std::max_element(_container.begin(), _container.end());
	
	return (max - min);
}


const char* Span::NoMoreSpaceException::what() const throw()
{
	return "No more space available!";
}


const char* Span::NotEnoughMembers::what() const throw()
{
	return "Not enough members!";
}

