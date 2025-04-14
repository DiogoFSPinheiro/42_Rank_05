#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if(!target)
		return ;

	std::map<std::string, ATarget * >::iterator it = _targets.find(target->getType());

	if (it != _targets.end())
		return ;

	_targets.insert(std::make_pair(target->getType(), target->clone()));
}


void TargetGenerator::forgetTargetType(const std::string& type)
{
	std::map<std::string, ATarget * >::iterator it = _targets.find(type);

	if (it == _targets.end())
		return ;

	delete it->second;
	_targets.erase(type);
}


ATarget* TargetGenerator::createTarget(const std::string& target)
{
	std::map<std::string, ATarget * >::iterator it = _targets.find(target);

	if (it == _targets.end())
		return NULL;

	return it->second->clone();
}
