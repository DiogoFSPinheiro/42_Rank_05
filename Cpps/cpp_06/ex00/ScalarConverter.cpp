/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/05 01:53:13 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string value)
{
	if (isCharLiteral(value) && !std::isdigit(value[0]))
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

		std::cout << "char: " << (nbrFloat >= 0 && nbrFloat <= 127 && isprint(nbrFloat) ?
			"'" + std::string(1, static_cast<char>(nbrFloat)) + "'" :
			"Non displayable") << std::endl;

		if (nbrFloat < std::numeric_limits<int>::min() || nbrFloat > std::numeric_limits<int>::max())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nbrFloat) << std::endl;

		if (nbrFloat < std::numeric_limits<float>::min() || nbrFloat > std::numeric_limits<float>::max())
			std::cout << "float: overflow" << std::endl;
		else
			std::cout << "float: " << nbrFloat << ".0f" << std::endl;

		std::cout << "double: " << static_cast<double>(nbrFloat) << ".0" << std::endl;
	}
	else if (isDoubleLiteral(value))
	{
		float nbrDou = std::strtod(value.c_str(), NULL);

		std::cout << "char: " << (nbrDou >= 0 && nbrDou <= 127 && isprint(nbrDou) ?
			"'" + std::string(1, static_cast<char>(nbrDou)) + "'" :
			"Non displayable") << std::endl;

		if (nbrDou < std::numeric_limits<int>::min() || nbrDou > std::numeric_limits<int>::max())
			std::cout << "int: overflow" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(nbrDou) << std::endl;

		if (nbrDou < std::numeric_limits<float>::min() || nbrDou > std::numeric_limits<float>::max())
			std::cout << "float: overflow" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(nbrDou) << ".0f" << std::endl;

		if (nbrDou < std::numeric_limits<double>::min() || nbrDou > std::numeric_limits<double>::max())
			std::cout << "double: overflow" << std::endl;
		else
			std::cout << "double: " << nbrDou << ".0f" << std::endl;
	}

	
	else
        std::cout << "Error: Unknown literal type" << std::endl;

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

bool ScalarConverter::isDoubleLiteral(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
        return true;
	
   
	int c = 0;
	bool hasDecimalPoint = false;
	bool hasExponent = false;

	if (value[0] == '+' || value[0] == '-') 
		c = 1;

	while (c < value.length())
	{
		if (value[c] == '.')
		{
			if (hasDecimalPoint) 
				return false;
			hasDecimalPoint = true;
		} 

		else if ((value[c] == 'e' || value[c] == 'E') && !hasExponent)
		{
			hasExponent = true;
			if (c + 1 < value.length() && std::isdigit(value[c + 1]))
				c++;
			else
				return false;
		} 
		else if (!std::isdigit(value[c])) 
			return false;
		c++;
	}

		return true;
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




