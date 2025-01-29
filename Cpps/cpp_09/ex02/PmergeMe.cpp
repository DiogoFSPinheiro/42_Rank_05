/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/29 22:49:37 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <stdexcept>

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


void PmergeMe::FordJohnson()
{
    std::cout << std::fixed << std::setprecision(2);
	
	printNumbers(0);
	clock_t start = clock();
    mergeInsertionSort(_vector, 1);
    clock_t end = clock();
	printNumbers(1);
	
	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << (float)(end - start) * 1000 / CLOCKS_PER_SEC << " ms" << std::endl;

}

void PmergeMe::printNumbers(int time)
{
	int c = -1;
	std::cout << (time ? "After:    ":  "Before:   " );
	while (++c < this->vectorSize())
		std::cout << this->getVectorPosition(c) << " ";
	std::cout << std::endl;
}

bool	compareVector(Iterator lv, Iterator rv)
{
	return *lv < *rv;
}

bool	compareDeque(Iterator_Deque lv, Iterator_Deque rv)
{
	return *lv < *rv;
}

std::vector<int>::iterator PmergeMe::next(std::vector<int>::iterator it, int steps)
{
	std::advance(it, steps);
	return it;
}

std::vector<Iterator>::iterator PmergeMe::next(std::vector<Iterator>::iterator it, int steps)
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

void PmergeMe::mergeInsertionSort(std::vector<int> &container, int pair_level)
{

	int pair_units_nbr = container.size() / pair_level;
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

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	main.insert(main.end(), next(container.begin(), pair_level - 1));
	main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

	for (int i = 4; i <= pair_units_nbr; i += 2)
	{
		pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
		main.insert(main.end(), next(container.begin(), pair_level * i - 1));
	}

	int prev_jacobsthal = jacobsthalNumber(1);
	int inserted_numbers = 0;

	for (int k = 2;; k++)
	{
		int curr_jacobsthal = jacobsthalNumber(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break;
		int nbr_of_times = jacobsthal_diff;

		std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
		std::vector<Iterator>::iterator bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers);
		
		while (nbr_of_times)
		{
			std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), bound_it, *pend_it, compareVector);
			std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);

			offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
        
		std::vector<Iterator>::iterator curr_bound = next(main.begin(), main.size() - pend.size() + i);
        
		std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, compareVector);

        main.insert(idx, *curr_pend);
    }

    if (is_odd)
    {
        Iterator odd_pair = next(end, pair_level - 1);
        std::vector<Iterator>::iterator idx = std::upper_bound(main.begin(), main.end(), odd_pair, compareVector);
        main.insert(idx, odd_pair);
    }

    std::vector<int> copy;
    copy.reserve(container.size());
    for (std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_level; i++)
        {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
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

long jacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
