/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/07 11:48:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer 
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer &operator=(const Serializer& other);
		~Serializer();

	public:
		
		static void convert(std::string value);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};


#endif