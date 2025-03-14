#include "PmergeMe.hpp"

void	swapBlocks(std::vector<int> &v, int elementSize) {
	
	size_t pos = elementSize - 1;
	size_t pos_to_compare = pos + elementSize;
	while(pos_to_compare < v.size()) {
		if (v[pos] > v[pos_to_compare]) {
			for(int i = 0; i < elementSize; i++) {
				std::swap(v[pos - i], v[pos_to_compare - i]);
			}
		}
		pos += elementSize * 2;
		pos_to_compare = pos + elementSize;
	}
}

int binarySearch(std::vector<int> &v, std::vector<int>::iterator itLimit, int toInsert) {

	int size, posLow, posHigh, posMid;

	size = v.size();
	posLow = 0;
	posMid = size / 2;
	if (itLimit != v.end())
		posHigh = std::distance(v.begin(), itLimit);
	else
		posHigh = size - 1;
	while(posLow <= posHigh) {
		posMid = posLow + ((posHigh - posLow) / 2);
		if (toInsert < v[posMid])
			posHigh = posMid - 1;
		else
			posLow = posMid + 1;
	}
	return posLow;
}

std::vector<int> initMainChain(std::vector<int> &v, std::vector<int> &a, std::vector<int> &b, size_t elementSize) {

	std::vector<int> mainChain;
	size_t posB1 = elementSize - 1;

	a.push_back(-1);
	b.push_back(-1);
	b.push_back(v[posB1]);
	
	size_t start = 0;
	while (start <= posB1)
		mainChain.push_back(v[start++]);
	size_t posA = start + elementSize - 1;
	while (posA < v.size()) {
		a.push_back(v[posA]);
		while(start <= posA)
			mainChain.push_back(v[start++]);
		posA = start + (elementSize * 2) - 1;
		start += elementSize;
	} 
	return mainChain;
}

std::vector<int> initPendChain(std::vector<int> &v, std::vector<int> &b, size_t elementSize) {

	std::vector<int> pendChain;
	
	size_t posB = (elementSize * 3) - 1; //starts at B2
	if (posB > v.size())
		return pendChain;
	size_t start = 1 + posB - elementSize;
	while(posB < v.size()) {
		b.push_back(v[posB]);
		while (start <= posB)
			pendChain.push_back(v[start++]);
		posB = start + (elementSize * 2) - 1;
		start+= elementSize;
	}
	return pendChain;
}

void	insertBlock(std::vector<int> &mainChain, int indexToInsert, std::vector<int> &pendChain, int elementTarget, size_t elementSize) {

	std::vector<int>::iterator itB = std::find(pendChain.begin(), pendChain.end(), elementTarget);
	for(size_t i = 0; i < elementSize; i++) {
		mainChain.insert(mainChain.begin() + indexToInsert * elementSize, *itB);
		itB = pendChain.erase(itB);
		itB--;
	}
}

void	updateMainTargets(std::vector<int> &mainChain, std::vector<int> &mainTargets, size_t elementSize) {

	mainTargets.clear();	
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
}

void	insertionByJacobsthal(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, std::vector<int> &mainTargets, std::vector<int> &pendTargets, size_t elementSize) {
	
	int i = 2;
	int index = 1;
	int binarySearchIndex;
	size_t currentJN = jacobsthalNumber(i);
	size_t prevJN = jacobsthalNumber(i - 1);
	std::vector<int>::iterator itLimit;

	while (currentJN - prevJN <= pendTargets.size()){
		while (index > 0) {
			std::vector<int>::iterator itB_InPendTargets = std::find(pendTargets.begin(), pendTargets.end(), b[currentJN]);//iterador para saber a posicao de B, se é B1, B2, B3...
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
		prevJN = currentJN;
		currentJN = jacobsthalNumber(++i);
		index = 1;
	}
}

void	insertionByOrder(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, std::vector<int> &mainTargets, std::vector<int> &pendTargets, size_t elementSize) {

	size_t index, binarySearchIndex;
	std::vector<int>::iterator itLimit;

	for (size_t i = 0; i < pendTargets.size();) {
		std::vector<int>::iterator itTargetInB = std::find(b.begin(), b.end(), pendTargets[i]); //iterador para saber a posicao de B, se é B1, B2, B3...
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

void	insertPendToMain(std::vector<int> &v, std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, size_t elementSize) {

	std::vector<int> mainTargets, pendTargets;
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
	for (size_t i = elementSize - 1; i < pendChain.size(); i+= elementSize) {
		pendTargets.push_back(pendChain[i]);
	}
	insertionByJacobsthal(mainChain, pendChain, a, b, mainTargets, pendTargets, elementSize);
	insertionByOrder(mainChain, pendChain, a, b, mainTargets, pendTargets, elementSize);
	for (size_t i = mainChain.size(); i < v.size(); i++)
		mainChain.push_back(v[i]);
}

std::vector<int>	createVector(int argc, char **argv) {
	std::vector<int> v;
	std::vector<int>::iterator itCheckDouble;
	long numberLong;
	
	for (int i = 1; i < argc; i++) {
		std::string input(argv[i]);
		std::istringstream stream(input);
		stream >> numberLong;
		itCheckDouble = std::find(v.begin(), v.end(), numberLong);
		if (numberLong <= std::numeric_limits<int>::max() && itCheckDouble == v.end())
			v.push_back(numberLong);
		else {
			if (itCheckDouble != v.end())
				printError("Numbers cannot be duplicated!");
			else 
				printError("Numbers must fit integer range!");
			return std::vector<int>();
		}
	}
	return v;
}