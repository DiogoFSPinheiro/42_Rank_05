#ifndef DUMMY
#define DUMMY

#include "ATarget.hpp"
#include <string>
#include <iostream>



class Dummy : public ATarget
{
	private:
		std::string _type;

	public:
		Dummy();
		~Dummy();

		ATarget *clone() const;
	

	
	
};





#endif
