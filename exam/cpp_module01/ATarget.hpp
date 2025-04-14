#ifndef ATARGET
#define ATARGET

#include "ASpell.hpp"
#include <string>
#include <iostream>

class Aspell;

class ATarget
{
	private:
		std::string _type;

	public:
		ATarget(std::string name);
		virtual ~ATarget();

		virtual ATarget *clone() const = 0;
	
		std::string getType() const;
		void getHitBySpell(const Aspell& spell) const;
	
	
};





#endif
