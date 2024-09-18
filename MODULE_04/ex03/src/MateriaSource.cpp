#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource -> Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_source[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	int i = 0;
	while(src._source[i]) {
		this->_source[i] = src._source[i];
		i++;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		int i = 0;
		while(src._source[i]) {
			this->_source[i] = src._source[i];
			i++;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource -> Destructor called" << std::endl;
	int i = 0;
	while(this->_source[i]) {
		delete(this->_source[i]);
		i++;
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	int i = 0;

	while(this->_source[i]) {
		i++;
	}
	if (i == 3)
		std::cout << "Materia Source is full!" << std::endl;
	else {
		std::cout << "New Materia " << m->getType() << " learned!" << std::endl;
		this->_source[i] = m;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	int i = 0;

	while(this->_source[i])
		i++;
	i--;
	while(this->_source[i]) {
		if (this->_source[i]->getType() == type) {
			std::cout << "Creating " << type << " materia" << std::endl;
			return (this->_source[i]->clone());
		}
		i--;
	}
	std::cout << "Unknown type! No Materia created!" << std::endl;
	return 0;
}

void MateriaSource::copySource(const MateriaSource &src) {
	int i = 0;
	while(this->_source[i]) {
		delete(this->_source[i]);
		i++;
	}
	i = 0;
	while(src._source[i]) {
		this->_source[i] = src._source[i];
		i++;
	}
}
