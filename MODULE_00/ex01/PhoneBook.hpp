
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	
	public:
		PhoneBook();
		~PhoneBook();
		void addNewContact(int contacts	);
		void searchContact();
		int displayContactList();
		void displayChosenContact(int inputNumber);
	
	private:
		Contact _contactList[8];
};

#endif
