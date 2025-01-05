/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/04 23:54:05 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>

#include "ScalarConverter.hpp"

int main(int argc, char *agrv[])
{
    ScalarConverter::convert(agrv[1]);

    //ScalarConverter::convert("22253651");
    
    //std::cout << agrv[1] << std::endl;
    
    return 0;
}



