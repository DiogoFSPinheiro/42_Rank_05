/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:18:39 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/07 22:24:26 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>


int main()
{
  Data data = {42, "Hello Besto Furendo"};
    
  std::cout << "Original Data: id = " << data.id << ", name = " << data.name << std::endl;

  // Serialize the data
  uintptr_t raw = Serializer::serialize(&data);
  
  // Deserialize it back
  Data* deserializedData = Serializer::deserialize(raw);
  
  std::cout << "Deserialized Data: id = " << deserializedData->id << ", name = " << deserializedData->name << std::endl;
  
  return 0;
}






