#include "Polymorph.hpp"


Polymorph::Polymorph() : Aspell("Polymorph", "turned into a critter")
{

}
Polymorph::~Polymorph()
{

}

Aspell *Polymorph::clone() const
{
	return new Polymorph;
}
	
