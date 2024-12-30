/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/30 19:47:25 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Deafult"), _gradeToExec(149), _gradeToSign(150), _target("Deafult")
{
	_isSigned  = false;
	std::cout << "Default constructor called!" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExec, const std::string target) 
	: _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign), _target(target)
{
	if (_gradeToExec < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	_isSigned  = false;
	std::cout << "Data constructor called!" << std::endl;
}

AForm::AForm(const AForm& copy) 
	: _name(copy._name), _gradeToExec(copy._gradeToExec), _gradeToSign(copy._gradeToSign) , _isSigned(copy._isSigned), _target(copy._target)
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

std::string AForm::getTarget() const
{
	return this->_target;
}

std::ostream& operator<<(std::ostream &ouput, const AForm& show)
{
	std::string done = "Unsigned";

	if (show.getIsSigned())
		done = "Signed";
	ouput << "AForm: " << show.getName() << " needs " << show.getSignGrade() << " to be signed and " << show.getExecGrade() << " to execute, status: " << done << ". The target is " << show.getTarget();
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

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

void 	AForm::beSigned(const Bureaucrat &a)
{
	if (this->_gradeToSign >= a.getGrade())
	{
		if (this->_isSigned)
			throw AlreadySignedException();
		this->_isSigned = true;
	}
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_gradeToExec >= executor.getGrade())
	{
		if (this->_isSigned)
		{
			std::cout << green << this->getName() << " executed by: " << executor.getName() << reset << std::endl;
			this->executor();	
		}
		else
			std::cout <<  this->getName() << " is not signed! So it can't be executed!" << std::endl;
	}
	else
		throw GradeTooLowException();
}
