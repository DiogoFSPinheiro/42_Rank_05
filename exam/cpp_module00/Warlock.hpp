
#ifndef WARLOCK
#define WARLOCK

#include <string>
#include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string	_title;

	public:
		Warlock(std::string name, std::string codeName);
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string codeName);
		
		void introduce() const;

};



#endif