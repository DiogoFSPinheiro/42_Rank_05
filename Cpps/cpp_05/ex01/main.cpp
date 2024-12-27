/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 13:56:31 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
        Form form;
        std::cout << form << std::endl;
        std::cout << std::endl;
        Form form2("Crazy Stuff", 120, 50);
        std::cout << form2 << std::endl;
        std::cout << std::endl;

        Form form3;
        form3 = form2;
        std::cout << form3 << std::endl;

        std::cout << std::endl;
        Form form4(form2);
        std::cout << form4 << std::endl;
        
    }

    try
    {
        std::cout << cyan << "\n[TEST 1]" << reset << std::endl;
        Form form2("Crazy Stuff", 149, 1);
        
        Bureaucrat tommy("Tommy", 1);
        std::cout << tommy << std::endl;
        std::cout << form2 << std::endl;
        form2.beSigned(tommy);
        std::cout << form2 << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << red << "Exception: " << reset << e.what() << std::endl;
    }


    
    return 0;
}



