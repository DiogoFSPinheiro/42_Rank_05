/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:51:55 by diogosan          #+#    #+#             */
/*   Updated: 2025/01/27 15:48:19 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <climits>

void writeTransformedData(std::map <std::string, float> dataBase, std::string date, std::string value)
{
	std::map <std::string, float>::iterator it;

	it = dataBase.lower_bound(date);

	if (it != dataBase.begin() && (it == dataBase.end() || it->first != date))
		--it;
	
	std::cout << date << " => ";
	std::cout << value << " = ";
	std::cout << std::atof(value.c_str()) * it->second << std::endl;	
}


bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool wrongDashCount(const std::string& date)
{
    std::string looking = date.c_str();
	int c = 0, dashCount = 0;
	
    while (looking[c])
	{
        if (looking[c] == '-')
            dashCount++;
		c++;
    }
    return dashCount > 2;
}

bool checkDate(std::string date)
{
	if (wrongDashCount(date))
		return false;
		
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	std::string year = date.substr(0, date.find("-"));
	std::string month = date.substr(5, date.find("-") - 2);
	std::string day = date.substr(8, 9);

	int yearI = std::atof(year.c_str());
	int monthI = std::atof(month.c_str());
	int dayI = std::atof(day.c_str());
		
	if (yearI > 2100)
		return false;
	if (monthI > 12 || monthI < 1)
		return false;
	
	int monthDays[] = {31, (isLeapYear(yearI) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (dayI > monthDays[monthI - 1] || dayI < 1)
		return false;

	return true;
}

bool  checkInput(std::string date, std::string value)
{
	if (date.length() != 10 || !checkDate(date))
	{
		std::cout << "Error: Wrong date format" << std::endl;
		return false;
	}
	if (!isUnsignedNumber(value))
		return false;
	return true;
}


void BitcoinExchange::readUserFile(std::string file)
{
	std::string dataArray;
	std::string date;
	std::string value;
	bool heather = true;
	std::ifstream dataFile(file.c_str());

	if (dataFile.fail())
		throw CantReadFile();
		
	while(getline(dataFile, dataArray))
	{
		if (dataArray.empty() || dataArray.find(" | ") == std::string::npos)
            std::cout << "Error: bad input => " << dataArray << std::endl;
		
		else if (!heather)
		{
			date = dataArray.substr(0, dataArray.find(" | ") );
			value = dataArray.substr(dataArray.find(" | ") + 3);
			if (checkInput(date, value))
				writeTransformedData(this->dataBase, date, value);
		}
		else
			heather = false;

	}
}

void BitcoinExchange::printDataBase()
{
	std::map<std::string, float>::iterator it = dataBase.begin();
	
	while (it != dataBase.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		++it;
	}

}

void BitcoinExchange::readCsvFile()
{
	std::string dataArray;
	std::string date;
	std::string value;
	bool heather = true;
	std::ifstream dataFile("data.csv");

	if (dataFile.fail())
		throw CantReadFile();

	while(getline(dataFile, dataArray))
	{
		if (!heather)
		{
			date = dataArray.substr(0, dataArray.find(","));
			value = dataArray.substr(dataArray.find(",") + 1);
			this->dataBase.insert(std::pair<std::string, float>(date, std::atof(value.c_str())));
		}
		else
			heather = false;

	}
}


BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
    *this = copy;
}
BitcoinExchange::~BitcoinExchange(){
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    //std::cout << "BitcoinExchange Assignment Operator Called" << std::endl;
    if (this != &other)
        this->dataBase = other.dataBase;
    return *this;
}

const char* BitcoinExchange::CantReadFile::what() const throw()
{
	return "Cant Read File: data.csv!";
}

bool isUnsignedNumber(std::string value)
{
	unsigned long c = 0;
	bool hasDecimalPoint = false;

	if (value[0] == '-')
	{
		std::cout << "Error: Negative number" << std::endl;
		return false;
	}
		
	if (value[0] == '+') 
		c = 1;

	while (c < value.length())
	{
		if (value[c] == '.')
		{
			if (hasDecimalPoint) 
				return false;
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(value[c])) 
		{
			std::cout << "Error: not a number" << std::endl;
			return false;
		}
			
		c++;
	}
	if (std::atof(value.c_str()) > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return false;
	}

	return true;
}
