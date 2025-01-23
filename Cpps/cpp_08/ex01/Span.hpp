/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 19:03:52 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _container;

	public:
		Span();
		Span(unsigned int size);
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &other);

		void	addNumber(int n);
		long	shortestSpan();
		long	longestSpan();
	
	class NoMoreSpaceException : public std::exception
	{
		const char* what() const throw();
	};

	class NotEnoughMembers : public std::exception
	{
		const char* what() const throw();
	};

};
#endif
