/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/02/03 14:47:52 by diogosan         ###   ########.fr       */
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


#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

int main(int argc, char **argv)
{
	
	
	try
	{
		std::cout << argc << " " << *argv << std::endl;
			
	}
	catch (std::exception &e)
	{
		std::cerr << red << "Error: " << e.what() << reset << std::endl;
	}
	
	return 0;
}