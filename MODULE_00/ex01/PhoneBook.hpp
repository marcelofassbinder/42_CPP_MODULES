
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contactList[8];
	public:
		PhoneBook();
		~PhoneBook();
		void addNewContact(int contacts	);
		void searchContact();
		int displayContactList();
		void displayChosenContact(int inputNumber);
};

#endif
