/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 09:09:25 by diogosan         ###   ########.fr       */
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

Span::Span(const Span &copy) : _size(copy._size)
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
        this->_container = other._container;
    }
    return *this;
}

void Span::addNumber(int n)
{
	if (_container.size() == _size)
		throw NoMoreSpaceException();
	_container.push_back(n);
}

void	Span::addRangeNumbers(int start, int end)
{
	unsigned int size;

	size = std::abs(end - start) + 1;
	
	if (_container.size() + size < size)
		throw NoSpaceRangeException();
	
	std::vector<int> range;
	range.reserve(size);
	
	if (end > start)
	{	
		while (start <= end)
			range.push_back(start++);
	}
	else
	{	
		while (end <= start)
			range.push_back(end++);
	}
	_container.insert(_container.end(), range.begin(), range.end());
}


long	Span::shortestSpan()
{
	if (_container.size() < 2)
		throw NotEnoughMembers();
	
	std::vector<int> organized = _container;
	std::sort(organized.begin(), organized.end());
	
	int	shortest = INT_MAX;
	size_t	c = 1;
	
	while (c < organized.size())
	{
		shortest = std::min(shortest, organized[c] - organized[c - 1]);
		c++;
	}
		
		
	return shortest;
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

const char* Span::NoSpaceRangeException::what() const throw()
{
	return "No space available to fill with range!";
}
