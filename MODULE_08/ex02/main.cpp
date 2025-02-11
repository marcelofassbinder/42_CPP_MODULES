#include <iostream>
#include <vector>
#include <list>
#include "MutantStack.hpp"

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

int main() {

	testSubject();
	testSubjectList();

	// test const it
	// test reverse it
	// test const_reverse it
	//	test receiving another container NOT DEQUE

/* 	MutantStack<int, std::vector<int>> a;

	a.push(2);
	a.push(4);
	a.push(6);
	a.push(8);
	a.push(10);

	a.print(); */
/* 
	MutantStack<int, std::vector<int>>::iterator itB = a.begin();
	MutantStack<int, std::vector<int>>::iterator itE = a.end();

	std::cout << "it begin = " << *itB << std::endl;
	std::cout << "it end = " << *(itE - 1) << std::endl;
	
	MutantStack<int, std::vector<int>> b;
	b = a;

	b.print();

	MutantStack<int, std::vector<int>> c(b);
	c.print();
 */
} 