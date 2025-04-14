#include "ASpell.hpp"
#include "ATarget.hpp"

Aspell::Aspell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}
Aspell::~Aspell()
{

}


	
std::string Aspell::getName() const
{
	return this->_name;
}

std::string Aspell::getEffects()const
{
	return this->_effects;
}

void Aspell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}