#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

#define RED "\e[31m"
#define BLUE "\e[34m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BOLD "\e[1m"
#define RESET "\e[0m"

void	testSubject(void) {
	std::cout << "\n- - - - - TEST 1: Subject - - - - - \n" << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
}

void	testSubjectList(void) {
	std::cout << "\n- - - - - TEST 2: Subject w/ list - - - - - \n" << std::endl;
	
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	
	std::cout << mstack.back() << std::endl;
	
	mstack.pop_back();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
}

void	testUnderlyingContainerVector() {
	std::cout << "\n- - - - - TEST 3: Creating mutant stack with a vector as underlying container - - - - - \n" << std::endl;

	MutantStack<char, std::vector<char> > ms;

	ms.push('m');
	ms.push('a');
	ms.push('r');
	ms.push('c');
	ms.push('e');
	ms.push('l');
	ms.push('o');

	ms.print();

	MutantStack<char, std::vector<char> >::iterator itB = ms.begin();
	MutantStack<char, std::vector<char> >::iterator itE = ms.end();

	std::cout << "iterator begin = " << *itB << std::endl;
	std::cout << "iterator (end - 1) = " << *(itE - 1) << std::endl;

	std::cout << "top element = " << ms.top() << std::endl;

}

void	testIterators() {
	std::cout << "\n- - - - - TEST 3: Testing all types of iterators - - - - - \n" << std::endl;

	MutantStack<std::string> ms;

	ms.push("first");
	ms.push("second");
	ms.push("third");

	ms.print();

	MutantStack<std::string>::iterator itB = ms.begin();
	MutantStack<std::string>::iterator itE = ms.end();
	MutantStack<std::string>::const_iterator constItB = ms.cbegin();
	MutantStack<std::string>::const_iterator constItE = ms.cend();
	MutantStack<std::string>::reverse_iterator revItB = ms.rbegin();
	MutantStack<std::string>::reverse_iterator revItE = ms.rend();

	std::cout <<GREEN<< "\niterator begin = " <<BOLD<< *itB << RESET << std::endl;
	std::cout <<YELLOW<< "const iterator begin = " <<BOLD<< *constItB << RESET << std::endl;
	std::cout <<BLUE<< "reverse iterator begin = " <<BOLD<< *revItB << RESET << std::endl;
	std::cout <<GREEN<< "iterator (end - 1) = " <<BOLD<< *(itE - 1) << RESET << std::endl;
	std::cout <<YELLOW<< "const iterator (end - 1) = " <<BOLD<< *(constItE - 1) << RESET << std::endl;
	std::cout <<BLUE<< "reverse iterator (end - 1) = " <<BOLD<< *(revItE - 1) << RESET << std::endl;
}

int main() {

	testSubject();
	testSubjectList();
	testUnderlyingContainerVector();
	testIterators();

	// test const it
	// test reverse it
	// test const_reverse it
	//	test receiving another container NOT DEQUE
} 