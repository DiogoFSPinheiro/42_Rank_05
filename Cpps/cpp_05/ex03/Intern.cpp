/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/31 16:43:57 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makeForm(const std::string formName, const std::string target)
{

	FormType options[] = {{"shrubbery request", &Intern::createShrubbery},
						  {"robotomy request", &Intern::createRobotomy},
						  {"presidential request", &Intern::createPresidential}};

	int i = 0;
	while (i < 3)
	{
		if (formName == options[i].name)
		{
			AForm *form = options[i].make(target);
			std::cout << "Intern created " << green << formName << reset <<std::endl;
			return form;
		}
		i++;
	}
	std::cerr << "Wrong form name" << std::endl;
	return NULL;
	
}

AForm *Intern::createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	std::cout << "Default constructor called!" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	(void)copy;
	std::cout << "Copy constructor called!" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor for Intern was called!" << std::endl;
}

Intern &Intern::operator=(const Intern& other)
{
	std::cout << "Assigment constructor for was called!" << std::endl;
	(void)other;
	return *this;
	
}
