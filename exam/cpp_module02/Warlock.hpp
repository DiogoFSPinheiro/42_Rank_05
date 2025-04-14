
#ifndef WARLOCK
#define WARLOCK

#include "ASpell.hpp"
#include "SpellBook.hpp"
#include <string>
#include <iostream>
#include <map>

class Warlock
{
	private:
		std::string _name;
		std::string	_title;
		SpellBook _spellBook;

	public:
		Warlock(std::string name, std::string codeName);
		~Warlock();

		std::string getName() const;
		std::string getTitle() const;
		void setTitle(const std::string codeName);
		
		void introduce() const;

		void learnSpell(Aspell *spell);
		void forgetSpell(const std::string &spell);
		void launchSpell(const std::string &spellName, ATarget &target);

};



#endif



