#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include "iostream"
#include "Colors.hpp"

class ICharacter;
class AMateria {
	
	protected:
		std::string _type;

	public: 
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria&);
		AMateria& operator=(const AMateria&);
		virtual ~AMateria();

		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif