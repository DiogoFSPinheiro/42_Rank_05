#ifndef POLYMORTH
#define POLYMORTH

#include "ASpell.hpp"
#include <string>
#include <iostream>



class Polymorph : public Aspell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		Polymorph();
		~Polymorph();

		Aspell *clone() const;
	

	
	
};





#endif
