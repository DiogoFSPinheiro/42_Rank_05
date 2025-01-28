/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/28 18:12:28 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 
#include <map>
#include <stack>
#include <algorithm>

class RPN
{
	private:
		std::stack<int> _container;

	public:
		RPN();
		RPN(const std::string &data);
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &other);

		void calculate(const std::string data);
		
	class MyException : public std::exception
	{
		const char* what() const throw();
	};

};

bool	seeSignal(char c);

#endif
