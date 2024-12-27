/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 18:56:39 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test default constructors, copy constructors, and assignment
    {
        std::cout << cyan << "\n[TEST 0] Constructors and Copy Mechanics" << reset << std::endl;
        Form form;
        std::cout << form << std::endl;
        std::cout << std::endl;

        Form form2("Crazy Stuff", 120, 50);
        std::cout << form2 << std::endl;
        std::cout << std::endl;
        Bureaucrat tommy("Tommy", 1);
        tommy.signForm(form2);

        Form form3;
        form3 = form2;
        std::cout << magenta << "Form3 (after assignment from Form2):" << reset << std::endl;
        std::cout << form3 << std::endl;

        std::cout << std::endl;
        Form form4(form2);
        std::cout << magenta << "Form4 (copy constructed from Form2):" << reset << std::endl;
        std::cout << form4 << std::endl;
        std::cout << std::endl;
    }

    std::cout << magenta << "\n--- Form Testing Suite ---" << reset << std::endl;
    try {
        std::cout << cyan << "\n[TEST 1] Signing Form Successfully" << reset << std::endl;
        Form form2("Top Secret", 149, 1);
        Bureaucrat tommy("Tommy", 1);

        std::cout << blue << "Before signing:" << reset << std::endl;
        std::cout << tommy << std::endl;
        std::cout << form2 << std::endl;

        tommy.signForm(form2);

        std::cout << green << "After signing:" << reset << std::endl;
        std::cout << form2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << red << "Exception: " << reset << e.what() << std::endl;
    }

    // Test signing a form with insufficient grade
    try {
        std::cout << cyan << "\n[TEST 2] Signing Form With Insufficient Grade" << reset << std::endl;
        Form form2("Confidential", 149, 1);
        Bureaucrat tommy("Tommy", 150);

        std::cout << blue << "Before signing:" << reset << std::endl;
        std::cout << tommy << std::endl;
        std::cout << form2 << std::endl;

        tommy.signForm(form2);

        std::cout << green << "After signing:" << reset << std::endl;
        std::cout << form2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << red << "Exception: " << reset << e.what() << std::endl;
    }

    // Test creating a form with an invalid grade
    try {
        std::cout << cyan << "\n[TEST 3] Creating Form With Invalid Grade (Too High)" << reset << std::endl;
        Form form("Impossible Form", 0, 10);
    }
    catch (const std::exception &e) {
        std::cerr << red << "Exception: " << reset << e.what() << std::endl;
    }

    try {
        std::cout << cyan << "\n[TEST 4] Creating Form With Invalid Grade (Too Low)" << reset << std::endl;
        Form form("Impossible Form", 151, 10);
    }
    catch (const std::exception &e) {
        std::cerr << red << "Exception: " << reset << e.what() << std::endl;
    }

    return 0;
}




