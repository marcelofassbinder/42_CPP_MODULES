#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <limits>

class PmergeMe {

	private:
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
	
	public:
	//VECTOR
	static void mergeInsertionSort(std::vector<int> &v);
	//DEQUE
	static void mergeInsertionSort(std::deque<int> &d);
};

void				printError(std::string error);
bool				checkInput(int argc, char **argv);	

//AUXILIAR FUNCTIONS - VECTOR

void				insertPendToMain(std::vector<int> &v, std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, size_t elementSize);
void				insertionByOrder(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, std::vector<int> &mainTargets, std::vector<int> &pendTargets, size_t elementSize);
void				insertionByJacobsthal(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, std::vector<int> &mainTargets, std::vector<int> &pendTargets, size_t elementSize);
void				updateMainTargets(std::vector<int> &mainChain, std::vector<int> &mainTargets, size_t elementSize);
void				insertBlock(std::vector<int> &mainChain, int indexToInsert, std::vector<int> &pendChain, int elementTarget, size_t elementSize);
void				swapBlocks(std::vector<int> &v, int elementSize);
void				printVector(std::vector<int> v);
int					binarySearch(std::vector<int> &v, std::vector<int>::iterator itLimit, int toInsert);
size_t 				jacobsthalNumber(int n);
std::vector<int> 	initPendChain(std::vector<int> &v, std::vector<int> &b, size_t elementSize);
std::vector<int> 	initMainChain(std::vector<int> &v, std::vector<int> &a, std::vector<int> &b, size_t elementSize);
std::vector<int>	createVector(int argc, char **argv);

//AUXILIAR FUNCTIONS - DEQUE

void				insertPendToMain(std::deque<int> &d, std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, size_t elementSize);
void				insertionByOrder(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, std::deque<int> &mainTargets, std::deque<int> &pendTargets, size_t elementSize);
void				insertionByJacobsthal(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, std::deque<int> &mainTargets, std::deque<int> &pendTargets, size_t elementSize);
void				updateMainTargets(std::deque<int> &mainChain, std::deque<int> &mainTargets, size_t elementSize);
void				insertBlock(std::deque<int> &mainChain, int indexToInsert, std::deque<int> &pendChain, int elementTarget, size_t elementSize);
void				swapBlocks(std::deque<int> &d, int elementSize);
void				printDeque(std::deque<int> d);
int					binarySearch(std::deque<int> &d, std::deque<int>::iterator itLimit, int toInsert);
size_t 				jacobsthalNumber(int n);
std::deque<int> 	initPendChain(std::deque<int> &d, std::deque<int> &b, size_t elementSize);
std::deque<int> 	initMainChain(std::deque<int> &d, std::deque<int> &a, std::deque<int> &b, size_t elementSize);
std::deque<int>		createDeque(int argc, char **argv);

#endif