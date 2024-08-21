#include "Harl.hpp"

int main(void) {
	Harl harlInstance;
	
	harlInstance.complain("DEBUG");
	harlInstance.complain("INFO");
	harlInstance.complain("WARNING");
	harlInstance.complain("ERROR");
}