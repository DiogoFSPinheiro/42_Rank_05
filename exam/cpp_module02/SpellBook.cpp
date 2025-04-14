
#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
	
}


void SpellBook::learnSpell(Aspell *spell)
{
	if (!spell)
		return ;

	std::map<std::string , Aspell* >::iterator it = _spellBook.find(spell->getName());

	if(it != _spellBook.end())
		return ;

	_spellBook.insert(std::make_pair(spell->getName(), spell->clone()));

}


void SpellBook::forgetSpell(const std::string &spell)
{
	std::map<std::string , Aspell* >::iterator it = _spellBook.find(spell);

	if(it == _spellBook.end())
		return ;

	delete it->second;
	_spellBook.erase(spell);

}

Aspell* SpellBook::createSpell(std::string const &name)
{
	std::map<std::string , Aspell* >::iterator it = _spellBook.find(name);
	if(it == _spellBook.end())
		return NULL;
	
	return it->second;
}