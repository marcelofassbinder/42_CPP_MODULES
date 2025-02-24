#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

template<typename T>

int	easyfind(T container, int toFind) {
	
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), toFind);
	if(it == container.end())
		throw "No occurence found";
	return *it;
}

#endif