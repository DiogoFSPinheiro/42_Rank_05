/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/31 16:08:26 by diogosan         ###   ########.fr       */
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
				throw std::runtime_error("Not an aceptable number!");
			if (std::atof(num.c_str()) > INT_MAX)
				throw std::runtime_error("Number above int max!");
			numbers.addArgs(atof(num.c_str()));
			argv++;
		}
		numbers.FordJohnson();
			
	}
	catch (std::exception &e)
	{
		std::cerr << red << "Error: " << e.what() << reset << std::endl;
	}
	
	return 0;
}