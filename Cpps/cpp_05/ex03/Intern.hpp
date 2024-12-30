/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/30 20:30:43 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "AForm.hpp"


class Intern 
{
	private:
		

	public:
		Intern();
		Intern(const Intern& copy);
		Intern &operator=(const Intern& other);
		virtual ~Intern();

	AForm *Intern::makeForm(const std::string formName, const std::string target);
	
	AForm *createShrubbery(const std::string &target);
    AForm *createRobotomy(const std::string &target);
    AForm *createPresidential(const std::string &target);

};



#endif