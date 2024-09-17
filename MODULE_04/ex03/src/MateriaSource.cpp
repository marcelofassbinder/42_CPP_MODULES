#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource -> Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->source[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		int i = 0;
		while(src.source[i]) {
			this->source[i] = src.source[i];
			i++;
		}
	}
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource -> Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;

	while(this->source[i]) {
		i++;
	}
	if (i == 3)
		std::cout << "Materia Source is full!" << std::endl;
	else {
		std::cout << "New Materia " << m->getType() << " learned!" << std::endl;
		this->source[i] = m;
	}
}

// createMateria