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
	
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _darkestSecret;
		std::string _phoneNumber;
};

int stringIsAlpha(std::string str);
int stringIsDigit(std::string str);

#endif