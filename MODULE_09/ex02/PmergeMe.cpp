#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {(void) src;}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	(void) src;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertionSort(std::vector<int> &v) {
	
	static size_t	elementSize = 1; //how many numbers are inside each element in a block(a group of 2 elements)
	
	if (elementSize > v.size() / 2) {
		elementSize /= 2;
		return ;
	}
	swapBlocks(v, elementSize);
	elementSize *= 2;
	PmergeMe::mergeInsertionSort(v);
	std::vector<int> mainChain, pendChain, a, b;
	mainChain = initMainChain(v, a, b, elementSize);
	pendChain = initPendChain(v, b, elementSize);
	insertPendToMain(v, mainChain, pendChain, a, b, elementSize);
	elementSize /= 2;
	v = mainChain;
}

void PmergeMe::mergeInsertionSort(std::deque<int> &d) {
	
	static size_t	elementSize = 1;
	
	if (elementSize > d.size() / 2) {
		elementSize /= 2;
		return ;
	}
	swapBlocks(d, elementSize);
	elementSize *= 2;
	PmergeMe::mergeInsertionSort(d);
	std::deque<int> mainChain, pendChain, a, b;
	mainChain = initMainChain(d, a, b, elementSize);
	pendChain = initPendChain(d, b, elementSize);
	insertPendToMain(d, mainChain, pendChain, a, b, elementSize);
	elementSize /= 2;
	d = mainChain;
}