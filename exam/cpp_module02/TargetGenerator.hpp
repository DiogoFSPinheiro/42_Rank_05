#ifndef TARGETGENERATOR
#define TARGETGENERATOR


#include "ATarget.hpp"
#include <string>
#include <iostream>
#include <map>


class TargetGenerator
{
	private:
		std::map<std::string, ATarget * > _targets;

	public:
		TargetGenerator();
		~TargetGenerator();
	
		void learnTargetType(ATarget* target);
		void forgetTargetType(const std::string& type);
		ATarget* createTarget(const std::string& target);


};



#endif


/*
* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type


*/