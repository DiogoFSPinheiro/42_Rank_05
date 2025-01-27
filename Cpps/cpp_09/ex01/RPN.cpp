/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 15:56:18 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <climits>


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
        return *this;
    return *this;
}

const char* RPN::MyException::what() const throw()
{
	return "Cant Read File: data.csv!";
}
