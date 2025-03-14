#include "PmergeMe.hpp"

void	testVector(int argc, char **argv) {
	
	clock_t start = clock();
	std::vector<int> v = createVector(argc, argv);
	if (v.empty())
		exit(EXIT_FAILURE);
	std::cout << "BEFORE: ";
	printVector(v);
	PmergeMe::mergeInsertionSort(v);
	clock_t end = clock();
	std::cout << "AFTER: ";
	printVector(v);
	std::cout << "Time to process a range of " << v.size() << " elements with \e[1;32mstd::vector\e[0m : " ;
	std::cout << std::fixed << std::setprecision(6) << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void	testDeque(int argc, char **argv) {
	
	clock_t start = clock();
	std::deque<int> d = createDeque(argc, argv);
	if (d.empty())
		exit(EXIT_FAILURE);
	PmergeMe::mergeInsertionSort(d);
	clock_t end = clock();
	std::cout << "Time to process a range of " << d.size() << " elements with \e[1;32mstd::deque\e[0m : " ;
	std::cout << std::fixed << std::setprecision(6) << static_cast<double>(end - start) / CLOCKS_PER_SEC << " seconds" << std::endl;
}

int main(int argc, char **argv) {

	if (checkInput(argc, argv)) {
		testVector(argc, argv);
		testDeque(argc, argv);
	}
	else
		printError("Input must be a list of positive integers");
}