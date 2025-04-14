
#ifndef WARLOCK
#define WARLOCK

#include "ASpell.hpp"
#include <string>
#include <iostream>
#include <map>

class Warlock
{
	private:
		std::string _name;
		std::string	_title;
		std::map< std::string, Aspell* > _spellBook;

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

/*
* learnSpell, takes a pointer to ASpell, that makes the Warlock learn a spell
* forgetSpell, takes a string corresponding a to a spell's name, and makes the
  Warlock forget it. If it's not a known spell, does nothing.
* launchSpell, takes a string (a spell name) and a reference to ATarget, that
  launches the spell on the selected target. If it's not a known spell, does
  nothing.





*/