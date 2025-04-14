#ifndef FIREBALL
#define FIREBALL

#include "ASpell.hpp"
#include <string>
#include <iostream>



class Fireball : public Aspell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		Fireball();
		~Fireball();

		Aspell *clone() const;
	

	
	
};





#endif
