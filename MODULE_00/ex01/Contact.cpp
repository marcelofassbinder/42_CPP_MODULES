#include "Contact.hpp"

Contact::Contact() {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_darkestSecret = "";
	this->_phoneNumber = "";
}

Contact::~Contact(){
}

void Contact::setFirstName() {
	while (1) {
		std::cout << BOLD BLUE << "FIRST NAME: " << RESET;
		std::getline(std::cin, this->_firstName);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsAlpha(this->_firstName) || this->_firstName.empty()) 
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setLastName() {
	while (1) {
		std::cout << BOLD BLUE << "LAST NAME:" << RESET;
		std::getline(std::cin, this->_lastName);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsAlpha(this->_lastName) || this->_lastName.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setNickname() {
	while (1) {
		std::cout << BOLD BLUE << "NICKNAME: " << RESET;
		std::getline(std::cin, this->_nickname);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsAlpha(this->_nickname) || this->_nickname.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setDarkestSecret() {
	while (1) {
		std::cout << BOLD BLUE << "DARKEST SECRET: " << RESET;
		std::getline(std::cin, this->_darkestSecret);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsAlpha(this->_darkestSecret) || this->_darkestSecret.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setPhoneNumber() {
	while (1) {
		std::cout << BOLD BLUE << "PHONE NUMBER: " << RESET;
		std::getline(std::cin, this->_phoneNumber);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			exit(0);
		}
		if (!stringIsDigit(this->_phoneNumber) || this->_phoneNumber.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

std::string Contact::getFirstName() {
	return this->_firstName;
}

std::string Contact::getLastName() {
	return this->_lastName;
}

std::string Contact::getNickname() {
	return this->_nickname;
}

std::string Contact::getDarkestSecret() {
	return this->_darkestSecret;
}

std::string Contact::getPhoneNumber() {
	return this->_phoneNumber;
}

int stringIsAlpha(std::string str) {
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return (0);
	}
	return (1);
}

int stringIsDigit(std::string str) {
	for (unsigned long i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]) && !std::isspace(str[i]) && str[i] != '+')
			return (0);
	}
	return (1);
}