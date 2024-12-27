/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 19:08:24 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class Form 
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;

	public:
		Form();
		Form(const std::string name, const int gradeToExec, const int gradeToSign);
		Form(const Form& copy);
		Form &operator=(const Form& other);
		~Form();

		int 	getExecGrade() const;
		int 	getSignGrade() const;
		bool 	getIsSigned() const;
		std::string getName() const;
		void 	beSigned(const Bureaucrat &a);
		

		
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream &ouput, const Form& show);


#endif