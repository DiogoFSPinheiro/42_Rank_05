/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:31 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/07 11:58:55 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}


Serializer::Serializer()
{
	std::cout << "Default constructor for Serializer called!" << std::endl;
}

Serializer::Serializer(const Serializer& copy)
{
	(void)copy;
	std::cout << "Copy constructor for Serializer called!" << std::endl;
}
Serializer::~Serializer()
{
	std::cout << "Destructor for Serializer was called!" << std::endl;
}

Serializer &Serializer::operator=(const Serializer& other)
{
	std::cout << "Assigment constructor for Serializer was called!" << std::endl;
	(void)other;
	return *this;
}




