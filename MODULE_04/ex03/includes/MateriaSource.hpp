#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

	private:
		AMateria *_source[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		MateriaSource& operator=(const MateriaSource&);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const &type);
		void copySource(const MateriaSource&);
};

#endif