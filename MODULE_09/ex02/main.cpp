#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void	printVector(std::vector<int> v) {
	std::vector<int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		std::cout << *it;
		if (it != v.end() - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

void	swapBlocks(std::vector<int> &v, int pos, int pos_to_swap, int blockSize) {

	for(int i = 0; i < blockSize / 2; i++) {
		std::swap(v[pos - i], v[pos_to_swap - i]);
	}
}

int binarySearch(std::vector<int> &v, int toInsert) {

	int size, posLow, posHigh, posMid;

	size = v.size();
	posLow = 0;
	posMid = size / 2;
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

std::vector<int> initMainChain(std::vector<int> &v, size_t blockSize) {
	//inicia com b1, a1, e depois o resto dos a's
	std::vector<int> mainChain;
	size_t	elementSize = blockSize / 2;

	//insert b1
	size_t posB1 = elementSize - 1;
	size_t start = 0;
	while (start <= posB1) {
		mainChain.push_back(v[start++]);
	}
	//insert a's
	size_t posA = start + elementSize - 1;
	while (posA < v.size()) {
		while(start <= posA) {
			mainChain.push_back(v[start++]);
		}
		posA = start + blockSize;
	}
	return mainChain;

}
//testar pendchain
std::vector<int> initPendChain(std::vector<int> &v, size_t blockSize) {
	//insert b's starting from b2
	std::vector<int> pendChain;
	size_t	elementSize = blockSize / 2;
	
	size_t posB = (elementSize * 3) - 1; //inicia no B2
	if (posB > v.size())
		return pendChain;
	size_t start = 1 + posB - elementSize;
	while(posB < v.size()) {
		while (start <= posB)
			pendChain.push_back(v[start++]);
			posB = start + blockSize;
		}
	return pendChain;
}

int 	jacobsthalNumber(int n) {
	return (pow(2, n + 1) + pow(-1, n)) / 3;
}

void	insertBlock(std::vector<int> &mainChain, int indexToInsert, std::vector<int> &pendChain, int elementTarget, size_t blockSize) {
	size_t elementSize = blockSize / 2;

	std::vector<int>::iterator itB = std::find(pendChain.begin(), pendChain.end(), elementTarget);
	for(size_t i = 0; i < elementSize; i++) {
		mainChain.insert(mainChain.begin() + indexToInsert * elementSize, *itB);
		itB--;
	}
	//erase PEND
}

void	insertPendToMain(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, size_t blockSize) {

	static int nth = 1;
	int elementSize = blockSize / 2;
	int jacobIndex = jacobsthalNumber(nth + 1) - jacobsthalNumber(nth);
	if (jacobIndex < b.size() - 1){}
		//insercao pelos numero de jacobsthal
	else {
		//criar um vetor da main so com os targets
		std::vector<int> mainTargets, pendTargets;
		for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
			mainTargets.push_back(mainChain[i]);
		}
		for (size_t i = elementSize - 1; i < pendChain.size(); i+= elementSize) {
			pendTargets.push_back(pendChain[i]);
		}
		for (size_t i = 0; i < pendTargets.size(); i++) {
			int search = binarySearch(mainTargets, pendTargets[i]);
			std::cout << "search = " << search << std::endl;
			//insertBlock
			insertBlock(mainChain, search, pendChain, pendTargets[i], blockSize);
			pendTargets.erase(pendTargets.begin() + i);
		}
		std::cout << "main after insertion" << std::endl;
		printVector(mainChain);	

		//inserir o bloco inteiro no lugar correto
	}
	std::cout << "jacobIndex = " << jacobIndex << std::endl;
}

std::vector<int> mergeInsertionSort(std::vector<int> &v) {

	static size_t blockSize = 2; //quantos numeros cada par possui. eh o conjunto de dois elementos
	size_t	elementSize = blockSize / 2; //quantos numeros cada elemento de um bloco possui
	std::cout << "blockSize = " << blockSize << std::endl;
	
	if (blockSize > v.size()) {
		blockSize /= 2;
		return v;
	}
	std::vector<int> a, b;
	a.push_back(-1);
	b.push_back(-1);
	size_t pos = elementSize - 1;
	size_t pos_to_compare = pos + elementSize;
	while(pos_to_compare < v.size()) {
		if (v[pos] > v[pos_to_compare]) {
			swapBlocks(v, pos, pos_to_compare, blockSize);
		}
		b.push_back(v[pos]);
		a.push_back(v[pos_to_compare]);
		pos += blockSize;
		pos_to_compare = pos + elementSize;
	}
	if (pos < v.size())
		b.push_back(v[pos]);
	std::cout << "vetor dos a's" << std::endl;
	printVector(a);
	std::cout << "vetor dos b's" << std::endl;
	printVector(b);
	blockSize *= 2;
	printVector(v);
	mergeInsertionSort(v);
	std::cout << "blockSize = " << blockSize << std::endl;
	std::vector<int> mainChain, pendChain;
	mainChain = initMainChain(v, blockSize);
	pendChain = initPendChain(v, blockSize);
	insertPendToMain(mainChain, pendChain, a, b, blockSize);
	//verificar se ha algum elemento perdido em v, que nao esta na main, e adiciona-lo(s)
	std::cout << "main" << std::endl;
	printVector(mainChain);
	std::cout << "pend" << std::endl;
	printVector(pendChain);
	blockSize /= 2;
	return mainChain;
}


int main() {
	//std::vector<int> v = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	std::cout << "BEFORE" << std::endl;
	std::vector<int> v = {7, 14, 11, 2, 9, 13, 3};
	printVector(v);

	v = mergeInsertionSort(v);
	printVector(v);

	/* std::cout << "DEPOIS DE TODA A RECURSIVIDADE" << std::endl;
	printVector(v); */
	/* std::cout << "BEFORE" << std::endl;
	printVector(v);
	ft_swap(v, 3, 7, 8);
	std::cout << "AFTER" << std::endl;
	printVector(v); */
}