/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Temps.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/08 21:52:20 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPS_HPP
#define TEMPS_HPP

#include <iostream>


template<typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename T>
T min(T a, T b)
{
	return (a < b) ? a : b;
}

template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

#endif