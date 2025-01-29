/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/29 11:33:44 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <stdexcept>


void RPN::calculate(const std::string data)
{
	std::istringstream input(data);
	std::string token;

	while (input >> token)
	{
		if (std::isdigit(token[0]))
		{
			long num = std::atof(token.c_str());
			_container.push(num);
		}

		else if (seeSignal(token[0]))
		{
			if (_container.size() > 2)
				throw std::runtime_error("Wrong amount of numbers for operation");
			
			int a = _container.top();
			_container.pop();
			int b = _container.top();
			_container.pop();
			
			switch (token[0])
			{
				case '+':
					_container.push(b + a);
					break;

				case '-':
					_container.push(b - a);
					break;

				case '*':
					_container.push(b * a);
					break;

				case '/':
					if (a == 0 || b == 0)
						throw std::runtime_error("Not possible to divide by 0");
					_container.push(b / a);
					break;
    		}
		}
	}
	if (_container.size() != 1)
		throw std::runtime_error("Error on operations");
		
	std::cout << "Solution: " << _container.top() << std::endl;
}

RPN::RPN(const std::string &data)
{
	calculate(data);	
}

RPN::RPN(){
}

RPN::RPN(const RPN &copy){
    *this = copy;
}

RPN::~RPN(){
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_container = other._container;
    return *this;
}

const char* RPN::MyException::what() const throw()
{
	return "My Exception!";
}


		
