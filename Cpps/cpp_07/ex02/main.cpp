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

#include <iostream>
#include <string>

#include "Array.tpp"

int main()
{
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
		std::cout << e.what() << std::endl;
	}

	return 0;
}



