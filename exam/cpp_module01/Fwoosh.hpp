#ifndef FWOOSH
#define FWOOSH

#include "ASpell.hpp"
#include <string>
#include <iostream>



class Fwoosh : public Aspell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		Fwoosh();
		~Fwoosh();

		Aspell *clone() const;
	

	
	
};





#endif
