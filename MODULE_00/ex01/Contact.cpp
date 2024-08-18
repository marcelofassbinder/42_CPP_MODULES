#include "Contact.hpp"

Contact::Contact() {
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->darkestSecret = "";
	this->phoneNumber = "";
}

Contact::~Contact(){
}

void Contact::setFirstName() {
	while (1) {
		std::cout << BOLD BLUE << "FIRST NAME: " << RESET;
		std::getline(std::cin, this->firstName);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			std::exit(0);
		}
		if (!stringIsAlpha(this->firstName) || this->firstName.empty()) 
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setLastName() {
	while (1) {
		std::cout << BOLD BLUE << "LAST NAME:" << RESET;
		std::getline(std::cin, this->lastName);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			std::exit(0);
		}
		if (!stringIsAlpha(this->lastName) || this->lastName.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setNickname() {
	while (1) {
		std::cout << BOLD BLUE << "NICKNAME: " << RESET;
		std::getline(std::cin, this->nickname);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			std::exit(0);
		}
		if (!stringIsAlpha(this->nickname) || this->nickname.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setDarkestSecret() {
	while (1) {
		std::cout << BOLD BLUE << "DARKEST SECRET: " << RESET;
		std::getline(std::cin, this->darkestSecret);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			std::exit(0);
		}
		if (!stringIsAlpha(this->darkestSecret) || this->darkestSecret.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

void Contact::setPhoneNumber() {
	while (1) {
		std::cout << BOLD BLUE << "PHONE NUMBER: " << RESET;
		std::getline(std::cin, this->phoneNumber);
		if (std::cin.eof()) {
			std::cout << BOLD RED << "\nEOF received, exiting Phone Book\n" << RESET << std::endl;
			std::exit(0);
		}
		if (!stringIsDigit(this->phoneNumber) || this->phoneNumber.empty())
			std::cout << BOLD RED << "\nInvalid input, please try again\n" << RESET << std::endl;
		else
			return ;
	}
}

std::string Contact::getFirstName() {
	return this->firstName;
}

std::string Contact::getLastName() {
	return this->lastName;
}

std::string Contact::getNickname() {
	return this->nickname;
}

std::string Contact::getDarkestSecret() {
	return this->darkestSecret;
}

std::string Contact::getPhoneNumber() {
	return this->phoneNumber;
}

int stringIsAlpha(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return (0);
	}
	return (1);
}

int stringIsDigit(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]) && !std::isspace(str[i]))
			return (0);
	}
	return (1);
}