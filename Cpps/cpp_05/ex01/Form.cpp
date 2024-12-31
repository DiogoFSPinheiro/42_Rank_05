/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 12:34:38 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Deafult"), _gradeToExec(149), _gradeToSign(150)
{
	_isSigned  = false;
	std::cout << "Default constructor called!" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign)
{
	if (_gradeToExec < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
	_isSigned  = false;
	std::cout << "Data constructor called!" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _gradeToExec(copy._gradeToExec), _gradeToSign(copy._gradeToSign) , _isSigned(copy._isSigned)
{
	std::cout << "Copy constructor called!" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor for Form was called!" << std::endl;
}

Form &Form::operator=(const Form& other)
{
	std::cout << "Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string Form::getName() const
{
	return this->_name;
}

int 	Form::getExecGrade() const
{
	return this->_gradeToExec;
}

int 	Form::getSignGrade() const
{
	return this->_gradeToSign;
}

bool 	Form::getIsSigned() const
{
	return this->_isSigned;
}

std::ostream& operator<<(std::ostream &ouput, const Form& show)
{
	std::string done = "Unsigned";

	if (show.getIsSigned())
		done = "Signed";
	ouput << "Form: " << show.getName() << " needs " << show.getSignGrade() << " to be signed and " << show.getExecGrade() << " to execute, status: " << done;
    return ouput;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too Low!";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Form is already signed!";
}

void 	Form::beSigned(const Bureaucrat &a)
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
