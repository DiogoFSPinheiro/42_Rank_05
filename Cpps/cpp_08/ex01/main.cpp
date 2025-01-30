/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:59 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/30 16:34:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include "Span.hpp"

int main()
{

	std::cout << "\nContainer size -> 3"<< std::endl;
	try
	{
		Span container(3);
		container.addNumber(5);
		container.addNumber(3);
		container.addNumber(10);
		std::cout << "Adding 5 , 3 and 10" << std::endl;
		std::cout << container.longestSpan() << std::endl;
		std::cout << container.shortestSpan() << std::endl << std::endl;
		std::cout << "Adding a 4th number..." << std::endl;
		container.addNumber(10);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: "<< e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\nContainer size -> 41"<< std::endl;
	try
	{
		Span container(41);
		
		std::cout << "Adding a range of 41 numbers: -20 , 20 "<< std::endl << std::endl;
		container.addRangeNumbers(-20, 20);
		std::cout << "Longest Span is :" << container.longestSpan() << std::endl;
		std::cout << "Shortest Span is :" << container.shortestSpan()  << std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: "<< e.what() << std::endl;
	}

		return 0;
}
