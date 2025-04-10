/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 20:24:47 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Jonny")
{
	_grade = 150;
	std::cout << "Default constructor for Bureaucrat called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << "Data constructor for Bureaucrat called!" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy constructor for Bureaucrat called!" << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for Bureaucrat was called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Assigment constructor for Bureaucrat was called!" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int 	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(int nbr)
{
	if (this->_grade - nbr > 0)
		this->_grade -= nbr;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade(int nbr)
{
	if (this->_grade + nbr < 151)
		this->_grade += nbr;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &ouput, const Bureaucrat& show)
{
	ouput << show.getName() << ", bureaucrat grade " << show.getGrade();
    return ouput;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}
