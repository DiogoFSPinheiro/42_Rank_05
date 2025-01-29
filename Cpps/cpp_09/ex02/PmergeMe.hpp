/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/29 22:44:01 by diogosan         ###   ########.fr       */
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

typedef std::vector<int>::iterator Iterator;
typedef std::deque<int>::iterator Iterator_Deque;

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		void	mergeInsertionSort(std::vector<int> & container, int pair_level);
		void	swapPair(std::vector<int>::iterator it, int pair_level);
		void	printNumbers(int time);
		static std::vector<int>::iterator next(std::vector<int>::iterator it, int steps);
		static std::vector<Iterator>::iterator next(std::vector<Iterator>::iterator it, int steps);
		

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &other);

		void	addArgs(int num);
		int		vectorSize();
		bool	sorted();
		int		getVectorPosition(unsigned int c);
		

		void	FordJohnson();


	class MyException : public std::exception
	{
		const char* what() const throw();
	};

};

long	jacobsthalNumber(long n);
bool	compareVector(Iterator lv, Iterator rv);
bool	compareDeque(Iterator_Deque lv, Iterator_Deque rv);

#endif
