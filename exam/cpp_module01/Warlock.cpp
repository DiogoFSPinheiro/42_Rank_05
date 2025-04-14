#include "Warlock.hpp"
#include "ASpell.hpp"
#include <map>
#include <utility>


void Warlock::learnSpell(Aspell *spell)
{
	if (!spell)
		return ;

	std::map<std::string , Aspell* >::iterator it = _spellBook.find(spell->getName());

	if(it != _spellBook.end())
		return ;

	_spellBook.insert(std::make_pair(spell->getName(), spell->clone()));

}


void Warlock::forgetSpell(const std::string &spell)
{
	std::map<std::string , Aspell* >::iterator it = _spellBook.find(spell);

	if(it == _spellBook.end())
		return ;

	delete it->second;
	_spellBook.erase(spell);

}


void Warlock::launchSpell(const std::string &spellName, ATarget &target)
{
	std::map<std::string , Aspell * >::iterator spell = _spellBook.find(spellName);
	if (spell == _spellBook.end())
		return ;

	spell->second->launch(target);

}



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