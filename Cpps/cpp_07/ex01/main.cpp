/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 22:31:55 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Temps.hpp"


void showInt(int c)
{
	std::cout << c << " ";
}

void showString(std::string c)
{
	std::cout << c << " ";
}

void showDouble(double d)
{
	std::cout << d << " ";
}

void showChar(char c)
{
    std::cout << c << " ";
}

int main()
{
	std::cout << "Test with an array of integers" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Integer array: ";
	iter(intArray, 5, showInt);
	std::cout << std::endl << std::endl;

	std::cout << "Test with an array of strings" << std::endl;
	std::string strArray[] = {"apple", "banana", "cherry"};
	std::cout << "String array: ";
	iter(strArray, 3, showString);
	std::cout << std::endl << std::endl;

	std::cout << "Test with an array of doubles" << std::endl;
	double doubleArray[] = {3.14, 2.71, 1.41};
	std::cout << "Double array: ";
	iter(doubleArray, 3, showDouble);
	std::cout << std::endl << std::endl;

	std::cout << "Test with a character array" << std::endl;
	char charArray[] = {'A', 'B', 'C', 'D'};
	std::cout << "Character array: ";
	iter(charArray, 4, showChar);
	std::cout << std::endl;

	return 0;
}



