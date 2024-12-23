/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:36:38 by diogosan          #+#    #+#             */
/*   Updated: 2024/12/10 18:24:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include <cstdio>

Dog::Dog()
{
	_type = "Dog";
	this->_brain = new Brain();
	std::cout << "DOG: Default constructor called!" << std::endl;
}

Dog::Dog(const Dog& other)
{
	std::cout << "DOG: Copy constructor called!" << std::endl;
	this->_brain = new Brain(*other._brain);
	*this = other;
}
Dog::~Dog()
{
	std::cout << "DOG: Destructor for " << this->_type << " was called!" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog& other)
{
	std::cout << "DOG: Assigment constructor for was called!" << std::endl;
	if (this != &other)
	{
		_type = other._type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout <<"wooof wooof wooof wooof wooof wooof wooof" <<std::endl;
}

void Dog::showIdeas(unsigned int nbr) const
{
	unsigned int i = 0;
	while (i < nbr-1)
		std::cout << this->_brain->getIdeas(i++) <<std::endl;
}

