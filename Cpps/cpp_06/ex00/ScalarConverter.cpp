/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/05 00:14:09 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string value)
{
	if (isCharLiteral(value))
	{
		std::cout << "char:" << value << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
	}
	else if (isIntLiteral(value))
	{
		long nbrInt = std::strtol(value.c_str(), NULL, 10);
		std::cout << "char: " << (nbrInt >= 0 && nbrInt <= 127 && isprint(nbrInt) ?
			"'" + std::string(1, static_cast<char>(nbrInt)) + "'" :
			"Non displayable") << std::endl;
		
		if (nbrInt < std::numeric_limits<int>::min() || nbrInt > std::numeric_limits<int>::max())
            std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << nbrInt << std::endl;
		std::cout << "float: " << static_cast<float>(nbrInt) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbrInt) << ".0" << std::endl;
	}
	else if (isFloatLiteral(value))
	{
		float nbrFloat = std::strtof(value.c_str(), NULL);
		std::cout << "float: " << nbrFloat << std::endl;
		std::cout << "double: " << static_cast<double>(nbrFloat) << ".0" << std::endl;
	}
	else {
        std::cout << "Error: Unknown literal type" << std::endl;
    }
}

bool ScalarConverter::isCharLiteral(std::string value)
{
	return value.length() == 1;
}

bool ScalarConverter::isIntLiteral(std::string value)
{
	int	c = 0;

	if (value[0] == '+' || value[0] == '-') 
        c = 1;
	while(c < value.length())
	{
		if (!std::isdigit(value[c]))
			return false;
		c++;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(std::string value)
{
	if (value == "nanf" || value == "+inff" || value == "-inff")
        return true;

	int c = 0;
	bool hasDecimalPoint = false;
	
	if (value[0] == '+' || value[0] == '-') 
		c = 1;
	while (c < value.length())
	{
		if (value[c] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		} 
		else if (value[c] == 'f' && c == value.length() - 1) {
			return hasDecimalPoint;
		}
		else if (!std::isdigit(value[c])) {
			return false;
		}
		c++;
	}
	return hasDecimalPoint;
}


ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor for ScalarConverter called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
	std::cout << "Copy constructor for ScalarConverter called!" << std::endl;
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor for ScalarConverter was called!" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "Assigment constructor for ScalarConverter was called!" << std::endl;
	(void)other;
	return *this;
}




