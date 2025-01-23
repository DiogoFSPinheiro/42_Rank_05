/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/09 13:56:09 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Array.tpp"

#define MAX_VAL 750

int main()
{
	std::cout << "\nMain from project!!"<<std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "\nNegative number access"<< std::endl;
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "\nMore than the size"<< std::endl;
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}


	std::cout << "\nMy testorinos!!"<<std::endl;
	try
	{
		Array<int> test;
		Array<int> testSize(22);
		Array<int> testCopy(testSize);
		Array<int> testEqual;
		Array<std::string> testString(27);

		testEqual = testSize;

		std::cout << test.getSize() << std::endl;
		std::cout << testCopy.getSize() << std::endl;
		std::cout << testSize.getSize() << std::endl;
		std::cout << testEqual.getSize() << std::endl;
		std::cout << std::endl;

		testSize.fillInt(2);
		std::cout << testSize[21] << std::endl;
		testString.fillString("hi i'm here");
		std::cout << testString[21] << std::endl;

		std::cout << testString[28] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}



