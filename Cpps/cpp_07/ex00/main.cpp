/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/07 22:03:29 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *agrv[])
{
    if (argc == 2)
		ScalarConverter::convert(agrv[1]);

    else
	 	std::cout << "Wrong nbr of args" << std::endl;
    
    return 0;
}



