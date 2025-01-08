/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 14:41:15 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "Base.hpp"


Base * generate(void)
{
	std::srand((unsigned) time(NULL));
	int choice = std::rand() % 3;
	if (choice == 0)
		return new A();
	else if (choice == 1)
		return new B();
	else
		return new C();
	
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "It's Type is: A."<< std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "It's Type is: B."<< std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "It's Type is: C."<< std::endl;
	else
		std::cout << "No type found."<< std::endl;

}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
        return ;
	} catch (const std::exception& e) {
	
	}
	
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
        return ;
	} catch (const std::exception& e) {
	
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
        return ;
	} catch (const std::exception& e) {
		std::cout << "Unknown type" << std::endl;
	}
}

int main()
{
    // Generate a random object of type A, B, or C
    Base* basePtr = generate();

    // Identify the type using a pointer
    std::cout << "Using pointer to identify: ";
    identify(basePtr);

    // Identify the type using a reference
    std::cout << "Using reference to identify: ";
    identify(*basePtr);

    // Clean up
    delete basePtr;

    return 0;
}






