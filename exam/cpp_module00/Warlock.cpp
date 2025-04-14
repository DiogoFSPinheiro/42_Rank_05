#include "Warlock.hpp"


Warlock::Warlock(std::string name, std::string codeName): _name(name), _title(codeName)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}


void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " <<  this->_title <<"!" << std::endl;
}


std::string Warlock::getName() const
{
	return this->_name;
}

std::string Warlock::getTitle() const
{
	return this->_title;
}

void Warlock::setTitle(const std::string codeName)
{
	this->_title = codeName;
}