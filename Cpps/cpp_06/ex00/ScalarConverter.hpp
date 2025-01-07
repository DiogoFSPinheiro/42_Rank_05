/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/07 11:48:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


#include <iomanip>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib> 
#include <cctype>

class ScalarConverter 
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter &operator=(const ScalarConverter& other);
		~ScalarConverter();
		static bool isCharLiteral(std::string value);
		static bool isIntLiteral(std::string value);
		static bool isFloatLiteral(std::string value);
		static bool isDoubleLiteral(std::string value);

	public:
		
		static void convert(std::string value);

};




#endif