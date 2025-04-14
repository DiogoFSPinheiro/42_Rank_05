#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget(std::string name) : _type(name)
{

}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return this->_type;
}

void ATarget::getHitBySpell(const Aspell& spell) const
{
	std::cout << this->_type << " has been " << spell.getEffects() <<"!" << std::endl;
}
	