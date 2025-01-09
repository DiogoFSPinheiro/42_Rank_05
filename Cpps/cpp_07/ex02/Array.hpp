/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:40:02 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/09 13:52:21 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>


template<typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int size);
        Array(const Array &copy);
        ~Array();

        Array &operator=(const Array& other);
        T &operator[](unsigned int c);

        unsigned int getSize() const;
        
        class OutOfBounds : public std::exception
        {
            const char* what() const throw();
        };

        void fillInt(int value);
        void fillString(const std::string &value);
   
};






#endif