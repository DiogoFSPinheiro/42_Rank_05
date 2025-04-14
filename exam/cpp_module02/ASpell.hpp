#ifndef ASPELL
#define ASPELL

#include <string>
#include <iostream>

class ATarget;

class Aspell
{
	private:
		std::string _name;
		std::string _effects;

	public:
		Aspell(std::string name, std::string effects);
		virtual ~Aspell();

		virtual Aspell *clone() const = 0;
	
		std::string getName() const;
		std::string getEffects()const ;
		void launch(const ATarget& target) const;
	
	
};





#endif
