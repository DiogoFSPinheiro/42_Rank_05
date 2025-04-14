#ifndef SPELLBOOK
#define SPELLBOOK


#include <string>
#include <iostream>
#include <map>

#include "ASpell.hpp"

class SpellBook
{
	private:
		std::map<std::string , Aspell* > _spellBook;


	public:
		SpellBook();
		~SpellBook();

		void learnSpell(Aspell *spell);
		void forgetSpell(const std::string &spell);
		Aspell* createSpell(std::string const &name);


	
	
};

#endif