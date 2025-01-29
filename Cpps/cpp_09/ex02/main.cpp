/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/29 15:38:17 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <climits>
#include <deque>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <string>
#include "PmergeMe.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

bool isNumber(std::string &str)
{
	std::string::iterator it = str.begin();

	while (it != str.end())
	{
		if (*it == '+')
			it++;
		if (!std::isdigit(*it))
			return false;
		it++;
	}
	return true;
}

void printNumbers(PmergeMe numbers, int time)
{
	int c = -1;
	std::cout << (time ? "After:    ":  "Before:   " );
	while (++c < numbers.vectorSize())
		std::cout << numbers.getVectorPosition(c) << " ";
	std::cout << std::endl;
}


int main(int argc, char **argv)
{
	PmergeMe numbers;
	
	try
	{
		if (argc < 3)
			throw std::runtime_error("Wrong number of args");
		argv++;
		while (*argv)
		{
			std::string num = *argv;
			if (!isNumber(num))
				throw std::runtime_error("Not a Number!");
			if (std::atof(num.c_str()) > INT_MAX)
				throw std::runtime_error("Number above int max!");
			numbers.addArgs(atof(num.c_str()));
			argv++;
		}
		printNumbers(numbers, 0);
		numbers.FordJohnson();
		printNumbers(numbers, 1);

		
	}
	catch (std::exception &e)
	{
		std::cerr << red << "Error: " << e.what() << reset << std::endl;
	}
	
	return 0;
}