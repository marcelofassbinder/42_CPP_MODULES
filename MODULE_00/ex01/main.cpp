#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(){

	int contacts = 0;
	PhoneBook pb;
	while(1)
	{
		std::string input;
		std::cout << BOLD << "\nChoose one option\n1 - ADD\n2 - SEARCH\n3 - EXIT\n-> " << RESET;
		std::getline(std::cin, input);

		if (input == "1" || input == "ADD")
			pb.addNewContact(contacts++);
		else if (input == "2" || input == "SEARCH")
			pb.searchContact();
		else if (input == "3" || input == "EXIT") {
			std::cout << "\nExiting Phone Book, bye bye!\n" << std::endl;
			break ;
		}
		else if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			break ;
		}
		else
			std::cout << BOLD RED << "\nInvalid option, please try again" << RESET << std::endl;
	}
}