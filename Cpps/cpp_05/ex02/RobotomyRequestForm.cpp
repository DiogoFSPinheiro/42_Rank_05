/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/28 18:37:10 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Deafult", 72, 45, "no target")
{
	std::cout << "Default constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Form", 72, 45, target)
{
	std::cout << "Data constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "Copy constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor for RobotomyRequestForm was called!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Assigment constructor for obotomyRequestForm was called!" << std::endl;
	if (this != &other)
        AForm::operator=(other); 
	return *this;
}

void RobotomyRequestForm::executor() const
{
	std::cout << cyan <<"Making some drilling noises...."  << reset <<std::endl;
	std::srand(time(NULL));
	int odds = std::rand() % 2;

	if (odds == 0)
		std::cout << red << "Robotomy Failed on " << this->getTarget() << reset <<  std::endl;
	
	else
		std::cout << green << this->getTarget() <<  " has been successfully robotomized!" << reset << std::endl;
}






