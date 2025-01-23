/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:59 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 22:59:43 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include "Span.hpp"

int main()
{
	

	try
	{
		Span container(5);
		
		container.addNumber(5);
		container.addNumber(3);
		container.addNumber(10);
		std::cout << container.longestSpan() << std::endl;
		std::cout << container.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: "<< e.what() << std::endl;
	}

	try
	{
		Span container(41);
		
		container.addRangeNumbers(-20, 20);
		std::cout << container.longestSpan() << std::endl;
		std::cout << container.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: "<< e.what() << std::endl;
	}
	
	return 0;

}
