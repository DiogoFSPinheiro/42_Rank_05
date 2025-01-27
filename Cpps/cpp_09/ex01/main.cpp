/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 15:14:48 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "BitcoinExchange.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

int main(int arc, char **argv)
{
	BitcoinExchange data;
	
	if (arc != 2 )
	{
		std::cout << red << "The expected input is -> ./btc file.txt"<< reset << std::endl;
		return 0;
	}
	
	try
	{
		data.readCsvFile();
		data.readUserFile(argv[1]);

	}
	catch (std::exception &e)
	{
		std::cerr << red << "Exception: " << reset << e.what() << std::endl;
	}
	
		
	return 0;
}