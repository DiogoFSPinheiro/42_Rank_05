/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 22:00:04 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include "easyFind.hpp"

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

int main()
{

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	std::cout << green << "Vector contains: 10, 20, 30, 40, 50" << reset << std::endl;
	try
	{
		std::vector<int>::iterator it;
		std::cout << "Looking for 30" << std::endl;
		it = easyFind(vec, 30);
		std::cout << "Found in vector: " << *it << std::endl << std::endl;
		std::cout << "Looking for 60" << std::endl;
		it = easyFind(vec, 60);
		std::cout << "Found in vector: " << *it << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Vector: " << e.what() << std::endl << std::endl;
	}

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	std::cout  << yellow << "List contains: 5, 15, 25" << reset << std::endl;
	try
	{
		std::list<int>::iterator it;
		std::cout << "Looking for 15" << std::endl;
		it = easyFind(lst, 15);
		std::cout << "Found in list: " << *it << std::endl << std::endl;

		std::cout << "Looking for 115" << std::endl;
		it = easyFind(lst, 115);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "List: " << e.what() << std::endl;
	}
	std::deque<int> deq;
	deq.push_back(5);
	deq.push_back(15);
	deq.push_front(25);
	std::cout << cyan << "\nDeque contains: 5, 15, 25" << reset << std::endl;
	try
	{
		std::deque<int>::iterator it;
		std::cout << "Looking for 15" << std::endl;
		it = easyFind(deq, 15);
		std::cout << "Found in list: " << *it << std::endl << std::endl;

		std::cout << "Looking for 115" << std::endl;
		it = easyFind(deq, 115);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "List: " << e.what()  << std::endl;
	}


	return 0;
}