#include "Fireball.hpp"


Fireball::Fireball() : Aspell("Fireball", "burnt to a crisp")
{

}
Fireball::~Fireball()
{

}

Aspell *Fireball::clone() const
{
	return new Fireball;
}
	
