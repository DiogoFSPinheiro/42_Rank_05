/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/28 19:52:12 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string value)
{
	std::cout << std::fixed << std::setprecision(1);
	
	if (isCharLiteral(value) && !std::isdigit(value[0]))
	{
		std::cout << "char: " << value << std::endl;
		std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << std::endl;
	}
	else if (isIntLiteral(value))
	{
		long nbrInt = std::strtol(value.c_str(), NULL, 10);
		std::cout << "char: " << (nbrInt >= 0 && nbrInt <= 127 && std::isprint(nbrInt) ? "'" + std::string(1, static_cast<char>(nbrInt)) + "'" :"Non displayable") << std::endl;
		
		if (nbrInt < std::numeric_limits<int>::min() || nbrInt > std::numeric_limits<int>::max())
			std::cout << "int:  impossible" << std::endl;
		else
			std::cout << "int: " << nbrInt << std::endl;
		std::cout << "float: " << static_cast<float>(nbrInt) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nbrInt)  << std::endl;
	}
	else if (isFloatLiteral(value))
	{
		float nbrFloat = std::strtof(value.c_str(), NULL);
		if (value == "+inff" || value == "-inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << value << std::endl;
			std::cout << ((value[0] == '+') ? "double: +inf"  : "double: -inf") << std::endl;
		}
		else if (value == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf"  << std::endl;
			std::cout <<  "double: nan" << std::endl;
		}
		else
		{
			std::cout << "char: " << (nbrFloat >= 0 && nbrFloat <= 127 && isprint(nbrFloat) ?
			"'" + std::string(1, static_cast<char>(nbrFloat)) + "'" :
			"Non displayable") << std::endl;
			if (nbrFloat < std::numeric_limits<int>::min() || nbrFloat > std::numeric_limits<int>::max())
				std::cout << "int:  impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(nbrFloat) << std::endl;

			std::cout << "float: " << nbrFloat << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(nbrFloat)  << std::endl;
		}
	}
	else if (isDoubleLiteral(value))
	{
		float nbrDou = std::strtod(value.c_str(), NULL);
		if (value == "+inf" || value == "-inf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << ((value[0] == '+') ? "float: +inff"  : "float: -inff") << std::endl;
			std::cout << "double: " << value << std::endl;
		}
		else if (value == "nan")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf"  << std::endl;
			std::cout <<  "double: nan" << std::endl;
		}
		else
		{
			std::cout << "char: " << (nbrDou >= 0 && nbrDou <= 127 && isprint(nbrDou) ?
			"'" + std::string(1, static_cast<char>(nbrDou)) + "'" :
			"Non displayable") << std::endl;
			if (nbrDou < std::numeric_limits<int>::min() || nbrDou > std::numeric_limits<int>::max())
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(nbrDou) << std::endl;


			std::cout << "float: " << static_cast<float>(nbrDou) << "f"<< std::endl;
			std::cout << "double: " << nbrDou << std::endl;
		}
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
	unsigned long	c = 0;

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

	unsigned long c = 0;
	bool hasDecimalPoint = false;
	bool hasF = false;
	
	if (value[0] == '+' || value[0] == '-') 
		c = 1;
	while (c < value.length())
	{
		if (value[c] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		} 
		else if (value[c] == 'f' && c == value.length() - 1)
			return true;

		else if (!std::isdigit(value[c]))
			return false;
		c++;
	}
	return hasF;
}

bool ScalarConverter::isDoubleLiteral(std::string value)
{
	if (value == "nan" || value == "+inf" || value == "-inf")
        return true;
	
	unsigned long c = 0;
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




