/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/28 18:37:10 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Deafult", 145, 137, "no target")
{
	std::cout << "Default constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137, target)
{
	std::cout << "Data constructor called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	*this = copy;
	std::cout << "Copy constructor called!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for ShrubberyCreationForm was called!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Assigment constructor for ShrubberyCreationForm was called!" << std::endl;
	if (this != &other)
        AForm::operator=(other); 
	return *this;
}

void ShrubberyCreationForm::executor() const
{
	std::string	fileName = (this->getTarget() + "_shrubbery");
	std::ofstream outputFile(fileName.c_str());
	if (outputFile.fail())
	{
		std::cout << red << "Error when creating a Shrubbery file!" << "\n" << reset << std::endl;
		return ;
	}
	else
	{
		outputFile << "          &&& &&  & &&" << std::endl;
		outputFile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		outputFile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		outputFile << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		outputFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		outputFile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		outputFile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		outputFile << "     &&     \\|||" << std::endl;
		outputFile << "             |||" << std::endl;
		outputFile << "             |||" << std::endl;
		outputFile << "             |||" << std::endl;
		outputFile << "       , -=-~  .-^- _" << std::endl;
		outputFile.close();
		std::cout << green << "File " << this->getTarget() << green << "_shrubbery created!" << "\n" << reset;
	}
}






