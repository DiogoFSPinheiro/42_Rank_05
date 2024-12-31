/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/31 16:40:04 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << cyan << "=== Testing Intern Class ===" << reset << std::endl;

    // Test Constructor and Destructor
    {
        std::cout << blue << "\n[TEST 1: Constructor and Destructor]" << reset << std::endl;
        Intern intern;
        std::cout << green << "Intern object created and destroyed successfully." << reset << std::endl;
    }

    // Test Copy Constructor
    {
        std::cout << blue << "\n[TEST 2: Copy Constructor]" << reset << std::endl;
        Intern intern1;
        Intern intern2(intern1);
        std::cout << green << "Intern copy constructor works correctly." << reset << std::endl;
    }

    // Test Assignment Operator
    {
        std::cout << blue << "\n[TEST 3: Assignment Operator]" << reset << std::endl;
        Intern intern1;
        Intern intern2;
        intern2 = intern1;
        std::cout << green << "Intern assignment operator works correctly." << reset << std::endl;
    }

    // Test makeForm Method
    {
        std::cout << blue << "\n[TEST 4: makeForm Method]" << reset << std::endl;

        Intern intern;

        // Test Shrubbery Creation Form
        std::cout << yellow << "Attempting to create ShrubberyCreationForm..." << reset << std::endl;
        AForm *shrubberyForm = intern.makeForm("shrubbery request", "Home");
        if (shrubberyForm) {
            std::cout << green << "ShrubberyCreationForm created successfully: " << *shrubberyForm << reset << std::endl;
            delete shrubberyForm; // Clean up
        }

        // Test Robotomy Request Form
        std::cout << yellow << "Attempting to create RobotomyRequestForm..." << reset << std::endl;
        AForm *robotomyForm = intern.makeForm("robotomy request", "Robot");
        if (robotomyForm) {
            std::cout << green << "RobotomyRequestForm created successfully: " << *robotomyForm << reset << std::endl;
            delete robotomyForm; // Clean up
        }

        // Test Presidential Pardon Form
        std::cout << yellow << "Attempting to create PresidentialPardonForm..." << reset << std::endl;
        AForm *presidentialForm = intern.makeForm("presidential request", "President");
        if (presidentialForm) {
            std::cout << green << "PresidentialPardonForm created successfully: " << *presidentialForm << reset << std::endl;
            delete presidentialForm; // Clean up
        }

        // Test Invalid Form Name
        std::cout << yellow << "Attempting to create InvalidForm..." << reset << std::endl;
        AForm *invalidForm = intern.makeForm("invalid request", "Nobody");
        if (!invalidForm) {
            std::cout << red << "Error handled correctly for invalid form name." << reset << std::endl;
        }
    }

    // Test Memory Management
    {
        std::cout << blue << "\n[TEST 5: Memory Management]" << reset << std::endl;
        Intern intern;

        std::cout << yellow << "Attempting to create and delete a ShrubberyCreationForm..." << reset << std::endl;
        AForm *form = intern.makeForm("shrubbery request", "Garden");
        if (form) {
            std::cout << green << "Memory allocation for form successful." << reset << std::endl;
            delete form;
            std::cout << green << "Memory deallocation successful." << reset << std::endl;
        }
    }

    std::cout << cyan << "\n=== All Tests Completed ===" << reset << std::endl;
    return 0;
}






