/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/28 19:10:50 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <deque>
#include <exception>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "RPN.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


bool	seeSignal(char c)
{
	return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

bool	parceArgs(std::string data)
{
	int c = 0;
	int size = data.size() - 1;

	while (c < size)
	{
		if (seeSignal(data[c]) && data[c + 1] == ' ')
			c++;
		else if (std::isdigit(data[c]) && !std::isdigit(data[c + 1]))
			c++;
		else if (data[c] == ' ' || data[c] == '	' )
			c++;
		else
			return false;
	}
	
	return true;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Wrong number of args" << std::endl;
		return 0;
	}
	if (parceArgs(argv[1]))
	{
		try{
			RPN notation(argv[1]);
		}
		catch(std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
		
	else
	{
		std::cerr << "Wrong Syntax, only numbers 0 -> 9 are accepted and check the Operators" << std::endl;
		return 0;
	}
		

	


	return 0;
}