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
		temp->content = m;
		temp->next = NULL;
		this->materiasAtFloor = temp;
		m->isEquiped = false;
		m->atFloor = true;
		return ;
	}
	while(temp->next){
		temp = temp->next;
	}
	temp->next = new ListOfMaterias;
	temp->next->content = m;
	temp->next->next = NULL;
	m->isEquiped = false;
	m->atFloor = true;
}

void	Floor::displayFloor(){

	ListOfMaterias *temp;

	std::cout << "DISPLAYING MATERIAS AVAILABLE AT FLOOR:" << std::endl;
	int i = 1;
	temp = this->materiasAtFloor;
	while(temp) {
		std::cout << i << "-> " << temp->content->getType() << std::endl; 
		temp = temp->next;
		i++;
	}
}

void	Floor::cleanFloor(AMateria *m){

	ListOfMaterias *temp;
	ListOfMaterias *toDelete;

	temp = this->materiasAtFloor;
	if (temp->content == m)
	{
		this->materiasAtFloor = temp->next;
		delete (temp);
		return ;
	}
	while(temp->next) {
		if (temp->next->content == m) {
			toDelete = temp->next;
			temp->next = temp->next->next;
			delete (toDelete);
			return ;
		}
		temp = temp->next;
	}
}

void Floor::cleanFloorMaterias() {
	
	ListOfMaterias *temp;

	while(this->materiasAtFloor) {
		temp = this->materiasAtFloor;
		delete(temp->content);
		this->materiasAtFloor = this->materiasAtFloor->next;
		delete(temp);
	}
	delete (this);
}
