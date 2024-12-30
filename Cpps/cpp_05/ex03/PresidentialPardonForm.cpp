/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/28 18:37:10 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Deafult", 25, 5, "no target")
{
	std::cout << "Default constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon", 25, 5, target)
{
	std::cout << "Data constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "Copy constructor called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for was called!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		return *this;
	}
	return *this;
}

void PresidentialPardonForm::executor() const
{
	std::cout << "Just to inform that "<< green << this->getTarget() <<  reset << " has been pardoned by Zaphod Beeblebrox."  << std::endl;
}






