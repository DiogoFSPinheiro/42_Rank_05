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

#include <iostream>
#include <string>

#include "Temps.hpp"

int main()
{
	std::cout << "Subject main"<< std::endl;
	{

		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}
	std::cout << std::endl;
	std::cout << "My Tests"<< std::endl;
	{
		std::cout << "Test 1: Swapping integers" << std::endl;
		int int1 = 42, int2 = 7;
		std::cout << "Before swap: int1 = " << int1 << ", int2 = " << int2 << std::endl;
		::swap(int1, int2);
		std::cout << "After swap: int1 = " << int1 << ", int2 = " << int2 << std::endl;

		std::cout << "\nTest 2: Swapping doubles"<< std::endl;
		double double1 = 3.14, double2 = 2.71;
		std::cout << "Before swap: double1 = " << double1 << ", double2 = " << double2 << std::endl;
		::swap(double1, double2);
		std::cout << "After swap: double1 = " << double1 << ", double2 = " << double2 << std::endl;

		std::cout << "\nTest 3: Swapping strings "<< std::endl;
		std::string str1 = "Hello", str2 = "World";
		std::cout << "Before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
		::swap(str1, str2);
		std::cout << "After swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;

		std::cout << "\nTest 4: Min and Max with different types "<< std::endl;
		std::cout << "min(" << int1 << ", " << int2 << ") = " << ::min(int1, int2) << std::endl;
		std::cout << "max(" << int1 << ", " << int2 << ") = " << ::max(int1, int2) << std::endl;

		std::cout << "min(" << double1 << ", " << double2 << ") = " << ::min(double1, double2) << std::endl;
		std::cout << "max(" << double1 << ", " << double2 << ") = " << ::max(double1, double2) << std::endl;

		std::cout << "min(\"" << str1 << "\", \"" << str2 << "\") = " << ::min(str1, str2) << std::endl;
		std::cout << "max(\"" << str1 << "\", \"" << str2 << "\") = " << ::max(str1, str2) << std::endl;

	}
	
	

	
	
    return 0;
}



