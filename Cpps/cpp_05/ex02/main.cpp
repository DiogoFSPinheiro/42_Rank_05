/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/30 12:16:33 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    
    PresidentialPardonForm form1("ola");
    RobotomyRequestForm formR("Robot");
    Bureaucrat Danny("Danny", 1);
    
    
    
    std::cout << formR << std::endl;

    Danny.signForm(form1);
    Danny.executeForm(form1);
    Danny.signForm(formR);
    Danny.executeForm(formR);



    return 0;
}




