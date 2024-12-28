/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 12:34:38 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Deafult"), _gradeToExec(149), _gradeToSign(150)
{
	_isSigned  = false;
	std::cout << "Default constructor called!" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (_gradeToExec < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	_isSigned  = false;
	std::cout << "Data constructor called!" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _gradeToExec(copy._gradeToExec), _gradeToSign(copy._gradeToSign) , _isSigned(copy._isSigned)
{
	std::cout << "Copy constructor called!" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor for was called!" << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
	std::cout << "Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string AForm::getName() const
{
	return this->_name;
}

int 	AForm::getExecGrade() const
{
	return this->_gradeToExec;
}

int 	AForm::getSignGrade() const
{
	return this->_gradeToSign;
}

bool 	AForm::getIsSigned() const
{
	return this->_isSigned;
}

std::ostream& operator<<(std::ostream &ouput, const AForm& show)
{
	std::string done = "Unsigned";

	if (show.getIsSigned())
		done = "Signed";
	ouput << "AForm: " << show.getName() << " needs " << show.getSignGrade() << " to be signed and " << show.getExecGrade() << " to execute, status: " << done;
    return ouput;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

void 	AForm::beSigned(const Bureaucrat &a)
{
	if (this->_gradeToSign >= a.getGrade())
		this->_isSigned = true;
	else
		throw GradeTooLowException();
}
