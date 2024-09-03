#include <iostream>

class Bird {

	private:
		std::string _name;
	
	public:
		virtual void talk();

};

class Chicken : public Bird {

	public:
		void talk();

};

class Duck : public Bird {

	public:
		void talk();
};

void Bird::talk(){
	std::cout << "fiufiu" << std::endl;
}

void Chicken::talk(){
	std::cout << "cocorico" << std::endl;
}

void Duck::talk(){
	std::cout << "quackquack" << std::endl;	
}

void all_talk(Bird *array[]) {
	for (int i = 0; i < 3; i++) {
		array[i]->talk();
	}
}

int main() {
	Bird bird;
	Chicken chicken;
	Duck duck;

	/* Bird *array[] = {&bird, &chicken, &duck};
	all_talk(array); */

	Bird *a = &chicken;

	a->talk();
}