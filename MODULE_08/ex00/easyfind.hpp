#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

template<typename T>

int	easyfind(T container, int toFind) {
	
	typename T::iterator it;

	for(it = container.begin(); it != container.end(); ++it)
		if (*it == toFind)
			return *it;
	throw "No occurence found";
}

#endif