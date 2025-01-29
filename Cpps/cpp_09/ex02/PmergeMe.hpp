/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/28 18:12:28 by diogosan         ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &other);

		void	addArgs(int num);
		int		vectorSize();
		int		getVectorPosition(unsigned int c);

		void	divideInPairsVector(int dept = 0);
		void	FordJohnson();
		bool	sorted();

		void mergeInsertionSort(std::vector<int> & container, int pair_level);
		void swapPair(std::vector<int>::iterator it, int pair_level);


	class MyException : public std::exception
	{
		const char* what() const throw();
	};

};

#endif
