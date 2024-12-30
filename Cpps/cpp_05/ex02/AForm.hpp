/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/30 11:59:35 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

#include <string>
#include <iostream>
#include <cstdlib>

class Bureaucrat;

class AForm 
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;
		const std::string _target;

	public:
		AForm();
		AForm(const std::string name, const int gradeToExec, const int gradeToSign, const std::string target);
		AForm(const AForm& copy);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

		int 	getExecGrade() const;
		int 	getSignGrade() const;
		bool 	getIsSigned() const;
		std::string getName() const;
		void 	beSigned(const Bureaucrat &a);
		std::string getTarget() const;
		void	execute(Bureaucrat const &executor) const;
		virtual void	executor() const = 0;

		

		
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &ouput, const AForm& show);


#endif