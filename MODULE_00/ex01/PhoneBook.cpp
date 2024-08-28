#include "PhoneBook.hpp"
#include <cstring>
#include <iomanip>

PhoneBook::PhoneBook() {
	std::cout << BLUE << "**** Phone Book created ****" << RESET << std::endl; 
}

PhoneBook::~PhoneBook() {
	std::cout << BLUE << "**** Phone Book deleted ****" << RESET << std::endl; 
}

void PhoneBook::addNewContact(int contacts) {
	
	if (contacts >= 8)
		std::cout << BOLD BLINK YELLOW << "\nPhone Book is full!\n" << RESET BOLD YELLOW << "New contact will replace the oldest one in the list!" << RESET << std::endl;
	contacts = contacts % 8;
	std::cout << MAGENTA << "\nAdding new contact...\n" << RESET << std::endl;
	this->_contactList[contacts].setFirstName();
	this->_contactList[contacts].setLastName();
	this->_contactList[contacts].setNickname();
	this->_contactList[contacts].setDarkestSecret();
	this->_contactList[contacts].setPhoneNumber();
	std::cout << BOLD GREEN << "\nNEW CONTACT ADDED" << RESET << std::endl;
}

void PhoneBook::searchContact() {

	std::cout << MAGENTA << "\nSearching contacts..." << RESET << std::endl;
	if (this->_contactList[0].getFirstName().empty()) {
		std::cout << BOLD YELLOW << "\nNO CONTACTS FOUND" << RESET << std::endl;
		return ;
	}
	std::cout << BOLD GREEN << "\n - - - - - - - SAVED CONTACTS - - - - - - - " << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" << RESET << std::endl;
	int i = this->displayContactList();
	std::string input;
	while (1) {
		std::cout << BOLD << "\nChoose an index to display: " << RESET; 
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsDigit(input) || input.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET;
		else {
			int inputNumber = std::atoi(input.c_str());
			if (inputNumber < 0 || inputNumber >= i) {
				std::cout << BOLD RED << "\nThis index is out of range, please try again\n" << RESET;
				continue ;
			}
			else
				return (this->displayChosenContact(inputNumber));
		}
	}
}

int PhoneBook::displayContactList() {
	int i = 0;
	while (i < 8 && !this->_contactList[i].getFirstName().empty()) {
		std::string first = this->_contactList[i].getFirstName();
		std::string last = this->_contactList[i].getLastName();
		std::string nick = this->_contactList[i].getNickname();
		if (first.length() > 10) {
			first = first.substr(0, 9);
			first.push_back('.');
		}
		if (last.length() > 10) {
			last = last.substr(0, 9);
			last.push_back('.');
		}
		if (nick.length() > 10) { 
			nick = nick.substr(0, 9);
			nick.push_back('.');
		}
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << first << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << "|" << std::endl;
		i++;
	}
	return (i);
}

void PhoneBook::displayChosenContact(int inputNumber) {
	std::cout << MAGENTA << "\nDisplaying chosen contact...\n" << std::endl;
	std::cout << BOLD BLUE << "FIRST NAME: " << RESET << this->_contactList[inputNumber].getFirstName() << std::endl;
	std::cout << BOLD BLUE << "LAST NAME: " << RESET << this->_contactList[inputNumber].getLastName() << std::endl;
	std::cout << BOLD BLUE << "NICKNAME: " << RESET << this->_contactList[inputNumber].getNickname() << std::endl;
	std::cout << BOLD BLUE << "DARKEST SECRET: " << RESET << this->_contactList[inputNumber].getDarkestSecret() << std::endl;
	std::cout << BOLD BLUE << "PHONE NUMBER: " << RESET << this->_contactList[inputNumber].getPhoneNumber() << std::endl;
}
