/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/02/03 13:07:27 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_H
#define PmergeMe_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <iomanip> 

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

typedef std::vector<int>::iterator Iterator;
typedef std::deque<int>::iterator Iterator_Deque;

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		bool	sorted();
		void	printNumbers(int time, std::string type);
		int		vectorSize();
		int		dequeSize();
		int		getVectorPosition(unsigned int c);
		int		getDequePosition(unsigned int c);

		/* Vector funcs*/
		void		mergeInsertionSort(std::vector<int> & container, int pair_level);
		static 		Iterator next(Iterator it, int steps);
		static 		std::vector<Iterator>::iterator next(std::vector<Iterator>::iterator it, int steps);
		static void	swapPair(std::vector<int>::iterator it, int pair_level);

		/* Deque funcs Overload*/
		void		mergeInsertionSort(std::deque<int> &container, int pair_level);
		static		Iterator_Deque next(Iterator_Deque it, int steps);
		static		std::deque<Iterator_Deque>::iterator next(std::deque<Iterator_Deque>::iterator it, int steps);
		static void	swapPair(std::deque<int>::iterator it, int pair_level);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &other);

		void	addArgs(int num);
		void	FordJohnson();


	class MyException : public std::exception
	{
		const char* what() const throw();
	};

};

long	jacobsthalNumber(long n);
std::vector<Iterator>::iterator binaryLook(std::vector<Iterator>::iterator start, std::vector<Iterator>::iterator end, Iterator num);

template<typename T>
int getDistance(typename T::iterator start, typename T::iterator end)
{
	int c = 0;

	for (typename T::iterator it = start; it != end; it++)
		c++;	
	return c;
}

template<typename T>
typename T::iterator binaryLook(typename T::iterator start, typename T::iterator end, typename T::value_type num)
{
	if (start == end)
		return start;

	typename T::iterator midle = start;

	std::advance(midle, getDistance<T>(start, end)/2);

	if (**midle > *num)
		return binaryLook<T>(start, midle, num);
	else
		return binaryLook<T>(midle + 1, end, num);
}

#endif
