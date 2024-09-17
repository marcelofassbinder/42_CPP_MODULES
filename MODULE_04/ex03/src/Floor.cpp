#include "../includes/Floor.hpp"

Floor* Floor::instance = NULL;

Floor::Floor() {
	this->materiasAtFloor = NULL;
}

Floor::Floor(const Floor&) {
}

Floor& Floor::operator=(const Floor&src) {
	(void) src;
	return (*this);
}

Floor::~Floor() {}

Floor* Floor::getInstance() {

	if (!instance) {
		instance = new Floor();
	}
	return instance;
}

ListOfMaterias* Floor::getMateriasAtFloor() const {
	return this->materiasAtFloor;
}

void Floor::leaveMateriaAtFloor(AMateria *m) {

	ListOfMaterias *temp;

	if (m->isEquiped == false) {
		std::cout << m->getType() << " is already at floor!" << std::endl;
		return ;
	}
	temp = this->materiasAtFloor;
	if (!temp) {
		temp = new ListOfMaterias;
		temp->current = m;
		temp->next = NULL;
		this->materiasAtFloor = temp;
		m->isEquiped = false;
		return ;
	}
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new ListOfMaterias;
	temp->next->current = m;
	temp->next->next = NULL;
	m->isEquiped = false;
}

void	Floor::displayFloor(){

	ListOfMaterias *temp;

	std::cout << "DISPLAYING MATERIAS AVAILABLE AT FLOOR:" << std::endl;
	int i = 1;
	temp = this->materiasAtFloor;
	while(temp) {
		std::cout << i << "-> " << temp->current->getType() << std::endl; 
		temp = temp->next;
		i++;
	}
}

void	Floor::cleanFloor(){
	
	ListOfMaterias *temp;

	while(this->materiasAtFloor) {
		temp = this->materiasAtFloor;
		delete(temp->current);
		this->materiasAtFloor = this->materiasAtFloor->next;
		delete(temp);
	}
	delete(this);
}
