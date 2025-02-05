/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:19:12 by mfassbin          #+#    #+#             */
/*   Updated: 2025/02/05 17:59:44 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
	std::cout << std::endl;
	{
		std::cout << "TEST 1 : ARRAY OF INTEGERS" << std::endl;

		int arrayInt[4] = {0, 2, 21, 7};

		std::cout << "----- Before -----" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
		}
		
		iter<int>(arrayInt, 7, changeToFortyTwo<int>);
		
		std::cout << "----- After -----" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "arrayInt[" << i << "] = " << arrayInt[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 : ARRAY OF CHARS" << std::endl;

		char arrayChar[] = "marcelo";

		std::cout << "----- Before -----" << std::endl;
		for (int i = 0; i < 7; i++) {
			std::cout << "arrayChar[" << i << "] = " << arrayChar[i] << std::endl;
		}
		
		iter<char>(arrayChar, 7, changeToFortyTwo<char>);

		std::cout << "----- After -----" << std::endl;
		for (int i = 0; i < 7; i++) {
			std::cout << "arrayChar[" << i << "] = " << arrayChar[i] << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 : ARRAY OF DOUBLES" << std::endl;

		double arrayDouble[] = {2.4, 7.3, 8.9, 7.653};

		std::cout << "----- Before -----" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "arrayDouble[" << i << "] = " << arrayDouble[i] << std::endl;
		}
		
		iter(arrayDouble, 4, changeToFortyTwo<double>);

		std::cout << "----- After -----" << std::endl;
		for (int i = 0; i < 4; i++) {
			std::cout << "arrayDouble[" << i << "] = " << arrayDouble[i] << std::endl;
		}
	}
}
