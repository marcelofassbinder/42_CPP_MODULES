/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:19:12 by mfassbin          #+#    #+#             */
/*   Updated: 2025/02/12 16:57:24 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template<typename T>
void	printArray(T *array, int len) {

	for (int i = 0; i < len; i++) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
}

void	testInt() {
	std::cout << "\nTEST 1 : ARRAY OF INTEGERS" << std::endl;

	int arrayInt[4] = {0, 2, 21, 7};

	std::cout << "----- Before -----" << std::endl;
	printArray(arrayInt, 4);
	
	iter<int>(arrayInt, 4, changeToFortyTwo<int>);
	
	std::cout << "----- After -----" << std::endl;
	printArray(arrayInt, 4);
}

void	testChar() {
	std::cout << "\nTEST 2 : ARRAY OF CHARS" << std::endl;

	char arrayChar[] = "marcelo";

	std::cout << "----- Before -----" << std::endl;
	printArray(arrayChar, 7);
	
	iter<char>(arrayChar, 7, changeToFortyTwo<char>);

	std::cout << "----- After -----" << std::endl;
	printArray(arrayChar, 7);
}

void	testString() {
	std::cout << "\nTEST 3 : ARRAY OF STRINGS" << std::endl;

	std::string arrayString[] = {"ola", "tudo", "bem", "?"};

	std::cout << "----- Before -----" << std::endl;
	printArray(arrayString, 4);
	
	iter(arrayString, 4, changeToFortyTwo<std::string>);

	std::cout << "----- After -----" << std::endl;
	printArray(arrayString, 4);
}

int main() {
	testInt();
	testChar();
	testString();
}

