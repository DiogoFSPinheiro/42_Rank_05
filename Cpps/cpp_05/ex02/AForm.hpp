/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/27 19:08:24 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

class AForm 
{
	private:
		const std::string _name;
		bool			  _isSigned;
		const int		  _gradeToSign;
		const int		  _gradeToExec;
		//TODO colocar aqui o target para ficar mais vooooooooooooooonito

	public:
		AForm();
		AForm(const std::string name, const int gradeToExec, const int gradeToSign);
		AForm(const AForm& copy);
		AForm &operator=(const AForm& other);
		virtual ~AForm();

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

std::ostream& operator<<(std::ostream &ouput, const AForm& show);


#endif