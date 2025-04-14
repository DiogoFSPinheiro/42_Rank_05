#ifndef BRICKWALL
#define BRICKWALL

#include "ATarget.hpp"
#include <string>
#include <iostream>



class BrickWall : public ATarget
{
	private:
		std::string _type;

	public:
		BrickWall();
		~BrickWall();

		ATarget *clone() const;
	

	
	
};





#endif
