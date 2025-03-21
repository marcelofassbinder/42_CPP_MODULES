#include "PmergeMe.hpp"

void	swapBlocks(std::deque<int> &d, int elementSize) {
	
	size_t pos = elementSize - 1;
	size_t pos_to_compare = pos + elementSize;
	while(pos_to_compare < d.size()) {
		if (d[pos] > d[pos_to_compare]) {
			for(int i = 0; i < elementSize; i++) {
				std::swap(d[pos - i], d[pos_to_compare - i]);
			}
		}
		pos += elementSize * 2;
		pos_to_compare = pos + elementSize;
	}
}

int binarySearch(std::deque<int> &d, std::deque<int>::iterator itLimit, int toInsert) {

	int size, posLow, posHigh, posMid;

	size = d.size();
	posLow = 0;
	posMid = size / 2;
	if (itLimit != d.end())
		posHigh = std::distance(d.begin(), itLimit);
	else
		posHigh = size - 1;
	while(posLow <= posHigh) {
		posMid = posLow + ((posHigh - posLow) / 2);
		if (toInsert < d[posMid])
			posHigh = posMid - 1;
		else
			posLow = posMid + 1;
	}
	return posLow;
}

std::deque<int> initMainChain(std::deque<int> &d, std::deque<int> &a, std::deque<int> &b, size_t elementSize) {

	std::deque<int> mainChain;
	size_t posB1 = elementSize - 1;

	a.push_back(-1);
	b.push_back(-1);
	b.push_back(d[posB1]);
	
	size_t start = 0;
	while (start <= posB1)
		mainChain.push_back(d[start++]);
	size_t posA = start + elementSize - 1;
	while (posA < d.size()) {
		a.push_back(d[posA]);
		while(start <= posA)
			mainChain.push_back(d[start++]);
		posA = start + (elementSize * 2) - 1;
		start += elementSize;
	} 
	return mainChain;
}

std::deque<int> initPendChain(std::deque<int> &d, std::deque<int> &b, size_t elementSize) {

	std::deque<int> pendChain;
	
	size_t posB = (elementSize * 3) - 1; //starts at B2
	if (posB > d.size())
		return pendChain;
	size_t start = 1 + posB - elementSize;
	while(posB < d.size()) {
		b.push_back(d[posB]);
		while (start <= posB)
			pendChain.push_back(d[start++]);
		posB = start + (elementSize * 2) - 1;
		start+= elementSize;
	}
	return pendChain;
}

size_t 	jacobsthalNumber(int n) {
	return (pow(2, n + 1) + pow(-1, n)) / 3;
}

void	insertBlock(std::deque<int> &mainChain, int indexToInsert, std::deque<int> &pendChain, int elementTarget, size_t elementSize) {

	std::deque<int>::iterator itB = std::find(pendChain.begin(), pendChain.end(), elementTarget);
	for(size_t i = 0; i < elementSize; i++) {
		mainChain.insert(mainChain.begin() + indexToInsert * elementSize, *itB);
		itB = pendChain.erase(itB);
		itB--;
	}
}

void	updateMainTargets(std::deque<int> &mainChain, std::deque<int> &mainTargets, size_t elementSize) {

	mainTargets.clear();	
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
}

void	insertionByJacobsthal(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, std::deque<int> &mainTargets, std::deque<int> &pendTargets, size_t elementSize) {
	
	int i = 2;
	int index = 1;
	int binarySearchIndex;
	size_t currentJN = jacobsthalNumber(i);
	size_t predJN = jacobsthalNumber(i - 1);
	std::deque<int>::iterator itLimit;

	while (currentJN - predJN <= pendTargets.size()){
		while (index > 0) {
			std::deque<int>::iterator itB_InPendTargets = std::find(pendTargets.begin(), pendTargets.end(), b[currentJN]);//iterador para saber a posicao de B, se é B1, B2, B3...
			if (itB_InPendTargets == pendTargets.end())
				index--;
			else
				index = std::distance(pendTargets.begin(), itB_InPendTargets);
			if (currentJN < a.size())
				itLimit = std::find(mainTargets.begin(), mainTargets.end(), a[currentJN]);//limit the binary search until that iterator(a1, a2, a3...)
			else
				itLimit = mainTargets.end();
			binarySearchIndex = binarySearch(mainTargets, itLimit, pendTargets[index]);
			insertBlock(mainChain, binarySearchIndex, pendChain, pendTargets[index], elementSize);
			pendTargets.erase(pendTargets.begin() + index);
			updateMainTargets(mainChain, mainTargets, elementSize);
		}
		predJN = currentJN;
		currentJN = jacobsthalNumber(++i);
		index = 1;
	}
}

void	insertionByOrder(std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, std::deque<int> &mainTargets, std::deque<int> &pendTargets, size_t elementSize) {

	size_t index, binarySearchIndex;
	std::deque<int>::iterator itLimit;

	for (size_t i = 0; i < pendTargets.size();) {
		std::deque<int>::iterator itTargetInB = std::find(b.begin(), b.end(), pendTargets[i]); //iterador para saber a posicao de B, se é B1, B2, B3...
		index = std::distance(b.begin(), itTargetInB);
		if (index < a.size())
			itLimit = std::find(mainTargets.begin(), mainTargets.end(), a[index]);
		else
			itLimit = mainTargets.end();
		binarySearchIndex = binarySearch(mainTargets, itLimit, pendTargets[i]);
		insertBlock(mainChain, binarySearchIndex, pendChain, pendTargets[i], elementSize);
		pendTargets.erase(pendTargets.begin() + i);
		updateMainTargets(mainChain, mainTargets, elementSize);
	}
}

void	insertPendToMain(std::deque<int> &d, std::deque<int> &mainChain, std::deque<int> &pendChain, std::deque<int> &a, std::deque<int> &b, size_t elementSize) {

	std::deque<int> mainTargets, pendTargets;
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
	for (size_t i = elementSize - 1; i < pendChain.size(); i+= elementSize) {
		pendTargets.push_back(pendChain[i]);
	}
	insertionByJacobsthal(mainChain, pendChain, a, b, mainTargets, pendTargets, elementSize);
	insertionByOrder(mainChain, pendChain, a, b, mainTargets, pendTargets, elementSize);
	for (size_t i = mainChain.size(); i < d.size(); i++)
		mainChain.push_back(d[i]);
}

std::deque<int>	createDeque(int argc, char **argv) {
	std::deque<int> d;
	std::deque<int>::iterator itCheckDouble;
	long numberLong;
	
	for (int i = 1; i < argc; i++) {
		std::string input(argv[i]);
		std::istringstream stream(input);
		stream >> numberLong;
		itCheckDouble = std::find(d.begin(), d.end(), numberLong);
		if (numberLong <= std::numeric_limits<int>::max() && itCheckDouble == d.end())
			d.push_back(numberLong);
		else {
			if (itCheckDouble != d.end())
				printError("Numbers cannot be duplicated!");
			else 
				printError("Numbers must fit integer range!");
			return std::deque<int>();
		}
	}
	return d;
}