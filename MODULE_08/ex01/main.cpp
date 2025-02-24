#include "Span.hpp"

void	testSubject() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 1: Subject - - - - - \n" << RESET << std::endl;
	
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

}

void	testFunctionality() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 2: Correct case - - - - - \n" << RESET << std::endl;
	
	Span a(5);

	a.addNumber(20);
	a.addNumber(15);
	a.addNumber(-10);
	a.print();

	std::cout << "shortest span = " << BOLD << a.shortestSpan() << RESET << std::endl;
	std::cout << "longest span = " << BOLD << a.longestSpan() << RESET << std::endl;

}

void	testAddNumberException() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 3: AddNumber exception - - - - - \n" << RESET << std::endl;
	
	Span a = Span(3);

	try {
		a.addNumber(2);
		a.addNumber(1);
		a.addNumber(4);
		a.addNumber(8);
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	testShortLongException() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 4: Shortest and longest span exception - - - - - \n" << RESET << std::endl;
	
	Span a(10);

	a.addNumber(4);

	try {
		std::cout << "shortest span = " << BOLD << a.shortestSpan() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
	try {
		std::cout << "longest span = " << BOLD << a.longestSpan() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << RED BOLD << "EXCEPTION CAUGHT: " << e.what() << RESET << std::endl;
	}
}

void	testFillFunction() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 5: Filling vector using a range of iterators - - - - - \n" << RESET << std::endl;
	
	Span a(5);

	a.addNumber(1);
	a.addNumber(2);
	a.addNumber(3);
	std::cout << "BEFORE FILL FUNCTION\n" <<std::endl;
	a.print();

	std::vector<int> v;
	v.push_back(100);
	v.push_back(101);

	a.fill(v.begin(), v.end());
	std::cout << "\nAFTER FILL FUNCTION\n" <<std::endl;

	a.print();

	std::cout << "\nshortest span = " << BOLD << a.shortestSpan() << RESET << std::endl;
	std::cout << "longest span = " << BOLD << a.longestSpan() << RESET << std::endl;
}

void	testManyNumbers() {
	std::cout << YELLOW BOLD << "\n - - - - TEST 6: Span with many numbers - - - - - \n" << RESET << std::endl;
	Span a(10001);

	for (int i = 0; i < 10001; i++) {
		a.addNumber(i);
	}

	std::cout << "shortest span = " << BOLD << a.shortestSpan() << RESET << std::endl;
	std::cout << "longest span = " << BOLD << a.longestSpan() << RESET << std::endl;

}

int main() {

	testSubject();
	testFunctionality();
	testAddNumberException();
	testShortLongException();
	testFillFunction();
	testManyNumbers();

}