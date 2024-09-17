#ifndef FLOOR_HPP
#define FLOOR_HPP

#include "AMateria.hpp"

//SINLETON DESIGN PATTERN - A way to access always the same instance in all the program
class AMateria;

typedef struct s_ListOfMaterias{
	AMateria *current;
	s_ListOfMaterias *next;
}				ListOfMaterias;

class Floor {

	private:
		//CANONICAL FORM
		Floor();
		Floor(const Floor&);
		Floor& operator=(const Floor&);
		~Floor();
		
		//LIST OF EXISTING MATERIAS
		ListOfMaterias *materiasAtFloor;

		//STATIC INSTANCE
		static Floor *instance;

	public:
		static Floor* getInstance();
		ListOfMaterias *getMateriasAtFloor() const;
		void	leaveMateriaAtFloor(AMateria *m);
		void	displayFloor();
		void	cleanFloor();
};

#endif