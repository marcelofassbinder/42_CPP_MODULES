#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : IMateriaSource {

	private:
		AMateria *source[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
};

#endif