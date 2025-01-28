/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:52:04 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/23 22:59:36 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_H
#define BitcoinExchange_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <iomanip>


class BitcoinExchange
{
	private:

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::map <std::string, float> dataBase;
		
		void readCsvFile();
		void readUserFile(std::string file);
		void printDataBase();
		

	class CantReadFile : public std::exception
	{
		const char* what() const throw();
	};

};
#endif

bool	checkInput(std::string date, std::string value);
bool	isUnsignedNumber(std::string value);
bool	isLeapYear(int year);
bool	wrongDashCount(const std::string& date);
bool	checkDate(std::string date);
void	writeTransformedData(std::map <std::string, float> dataBase, std::string date, std::string value);