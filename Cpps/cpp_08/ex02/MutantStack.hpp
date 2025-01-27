/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 10:00:59 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin();
		iterator end();
};



#endif
