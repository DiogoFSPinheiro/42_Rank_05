#include "Fwoosh.hpp"


Fwoosh::Fwoosh() : Aspell("Fwoosh", "fwooshed")
{

}
Fwoosh::~Fwoosh()
{

}

Aspell *Fwoosh::clone() const
{
	return new Fwoosh;
}
	
