/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:59 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 19:04:44 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <ostream>
#include "Span.hpp"

int main()
{
	Span container(5);

	try
	{
		container.addNumber(5);
		container.addNumber(10);
		std::cout << container.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: "<< e.what() << std::endl;
	}
	
	return 0;

}
