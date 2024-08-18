#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstring>

#define RESET "\e[0m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"

#define BOLD "\e[1m"
#define BLINK "\e[5m"

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string darkestSecret;
		std::string phoneNumber;
	public:
		Contact();
		~Contact();

		//	SETTERS
		void setFirstName();
		void setLastName();
		void setNickname();
		void setDarkestSecret();
		void setPhoneNumber();
		
		//	GETTERS
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string getDarkestSecret();
		std::string getPhoneNumber();
};

int stringIsAlpha(std::string str);
int stringIsDigit(std::string str);

#endif