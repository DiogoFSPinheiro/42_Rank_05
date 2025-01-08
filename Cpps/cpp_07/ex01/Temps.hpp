/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Temps.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 22:33:07 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPS_HPP
#define TEMPS_HPP

#include <cstddef>
#include <iostream>


template<typename T, typename Func >
void iter(T *array, unsigned long n, Func f)
{
	unsigned long c = 0;
	
	while (n > c)
		f(array[c++]);
	
}

#endif