/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/31 16:39:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

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

	AForm *makeForm(const std::string formName, const std::string target);
	
	struct FormType{
		std::string name;
		AForm *(*make)(const std::string &target);
	};
	
	static AForm *createShrubbery(const std::string &target);
    static AForm *createRobotomy(const std::string &target);
    static AForm *createPresidential(const std::string &target);

};



#endif