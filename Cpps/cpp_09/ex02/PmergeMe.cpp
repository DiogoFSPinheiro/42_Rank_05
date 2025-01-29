/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/28 19:16:00 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>



void PmergeMe::FordJohnson() {
    clock_t start = clock();
    mergeInsertionSort(_vector, 1);
    clock_t end = clock();

    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector: " << elapsedTime << " µs" << std::endl;
}


bool PmergeMe::sorted()
{
	size_t c = 0;
	size_t i = 0;

	while (c < _vector.size())
	{
		i = 0;
		while (i + 1< _vector.size())
		{
			if (_vector[c] > _vector[i])
				return false;
			i++;
		}
		c++;
	}
	return true;
}

void PmergeMe::divideInPairsVector(int dept)
{
    if (_vector.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> nextLevel;

	if (dept == 0)
	{
		for (size_t i = 0; i + 1 < _vector.size(); i += 2)
		{
			if (_vector[i] < _vector[i + 1])
				pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
			else
				pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));
		}
	}


	

	
    divideInPairsVector();
}


std::vector<int>::iterator next(std::vector<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

void PmergeMe::swapPair(std::vector<int>::iterator it, int pair_level)
{
	std::vector<int>::iterator start = next(it, -pair_level + 1);
	std::vector<int>::iterator end = next(start, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

void PmergeMe::mergeInsertionSort(std::vector<int> & container, int pair_level)
{
	typedef std::vector<int>::iterator Iterator;

	int pair_units_nbr = container.size() / pair_level;
	std::cout << pair_units_nbr << std::endl;
	if (pair_units_nbr < 2)
		return;

	bool is_odd = pair_units_nbr % 2 == 1;

	Iterator start = container.begin();
	Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
	Iterator end = next(last, -(is_odd * pair_level));

	int jump = 2 * pair_level;
	for (Iterator it = start; it != end; std::advance(it, jump))
	{
		Iterator this_pair = next(it, pair_level - 1);
		Iterator next_pair = next(it, pair_level * 2 - 1);
		if (*this_pair > *next_pair)
			swapPair(this_pair, pair_level);
	}
	mergeInsertionSort(container, pair_level * 2);

}

void PmergeMe::addArgs(int num)
{
	this->_vector.push_back(num);
	this->_deque.push_back(num);
}

int PmergeMe::vectorSize()
{
	return this->_vector.size();
}

int PmergeMe::getVectorPosition(unsigned int c)
{
	return this->_vector[c];
}


PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}

PmergeMe::~PmergeMe(){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
		this->_vector = other._vector, this->_deque = other._deque;
    return *this;
}

const char* PmergeMe::MyException::what() const throw()
{
	return "My Exception!";
}


		
