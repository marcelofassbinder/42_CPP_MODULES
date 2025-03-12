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

std::vector<int> initMainChain(std::vector<int> &v, std::vector<int> &a, std::vector<int> &b, size_t blockSize) {
	//inicia com b1, a1, e depois o resto dos a's
	std::vector<int> mainChain;
	size_t	elementSize = blockSize / 2;

	a.push_back(-1);
	b.push_back(-1);
	//insert b1
	size_t posB1 = elementSize - 1;
	b.push_back(v[posB1]);
	size_t start = 0;
	while (start <= posB1) {
		mainChain.push_back(v[start++]);
	}
	std::cout << "inseriu b1" << std::endl;
	printVector(mainChain);
	//insert a's
	size_t posA = start + elementSize - 1;
	while (posA < v.size()) {
		std::cout << "start = " << start;
		std::cout << " | posA = " << posA << std::endl;
		a.push_back(v[posA]);
		while(start <= posA) {
			std::cout << "inserindo a's" << std::endl;
			mainChain.push_back(v[start++]);
			printVector(mainChain);
		}
		posA = start + blockSize - 1;
		start += elementSize;
	} 
	return mainChain;

}

std::vector<int> initPendChain(std::vector<int> &v, std::vector<int> &b, size_t blockSize) {
	//insert b's starting from b2
	std::vector<int> pendChain;
	size_t	elementSize = blockSize / 2;
	
	size_t posB = (elementSize * 3) - 1; //inicia no B2
	if (posB > v.size())
		return pendChain;
	size_t start = 1 + posB - elementSize;
	while(posB < v.size()) {
		b.push_back(v[posB]);
		while (start <= posB)
			pendChain.push_back(v[start++]);
		posB = start + blockSize - 1;
		start+= elementSize;
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
		pendChain.erase(itB);
		itB--;
	}
}

void	updateMainTargets(std::vector<int> &mainChain, std::vector<int> &mainTargets, size_t blockSize) {

	int elementSize = blockSize / 2;

	mainTargets.clear();	
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
}

void	insertPendToMain(std::vector<int> &mainChain, std::vector<int> &pendChain, std::vector<int> &a, std::vector<int> &b, size_t blockSize) {

	int index = 1;
	int elementSize = blockSize / 2;
	int i = 2;
	int currentJN = jacobsthalNumber(i);
	int prevJN = jacobsthalNumber(i - 1);
	//insercao pelos numero de jacobsthal
	//criar um vetor da main so com os targets
	std::vector<int> mainTargets, pendTargets;
	for (size_t i = elementSize - 1; i < mainChain.size(); i+= elementSize) {
		mainTargets.push_back(mainChain[i]);
	}
	for (size_t i = elementSize - 1; i < pendChain.size(); i+= elementSize) {
		pendTargets.push_back(pendChain[i]);
	}
	while (currentJN - prevJN <= pendTargets.size()){
		while (index > 0) {
			std::cout << "JACOBSTHAAAAAAAL" << std::endl;
			std::cout << "currentJN = " << currentJN << " | prevJN = " << prevJN << std::endl;
			/* std::cout << "pendTargets" << std::endl;
			printVector(pendTargets); */
			size_t indexB = currentJN;
			/* std::cout << "vector dos B'S" << std::endl;
			printVector(b);
			std::cout << "b[indexB]" << b[indexB] << std::endl; */
			std::vector<int>::iterator findIndexOfPendTargets = std::find(pendTargets.begin(), pendTargets.end(), b[indexB]);//iterador para saber a posicao de B, se é B1, B2, B3...
			if (findIndexOfPendTargets == pendTargets.end())
				index--;
			else
				index = std::distance(pendTargets.begin(), findIndexOfPendTargets);
			std::vector<int>::iterator itLimit = std::find(mainTargets.begin(), mainTargets.end(), a[indexB]);
			std::cout << "quer inserir o numero " << pendTargets[index] << std::endl;
			int search = binarySearch(mainTargets, itLimit, pendTargets[index]);
			insertBlock(mainChain, search, pendChain, pendTargets[index], blockSize);
			pendTargets.erase(pendTargets.begin() + index);
			updateMainTargets(mainChain, mainTargets, blockSize);
			std::cout << "main after insertion" << std::endl;
			printVector(mainChain);
		}
		prevJN = currentJN;
		currentJN = jacobsthalNumber(++i);
		index = 1;
		std::cout << "**********ATUALIZOU ************" <<std::endl;
		std::cout << "currentJN = " << currentJN << " | prevJN = " << prevJN << std::endl;
	}	
	for (size_t i = 0; i < pendTargets.size();) {
		std::cout << "entrou" << std::endl;
		std::cout << "pendTargets" << std::endl;
		printVector(pendTargets);
		std::cout << "quer inserir o numero " << pendTargets[i] << std::endl;
		std::vector<int>::iterator findIndexOfB = std::find(b.begin(), b.end(), pendTargets[i]); //iterador para saber a posicao de B, se é B1, B2, B3...
		int index = std::distance(b.begin(), findIndexOfB);
		std::vector<int>::iterator itLimit = std::find(mainTargets.begin(), mainTargets.end(), a[index]);
		int search = binarySearch(mainTargets, itLimit, pendTargets[i]);
		insertBlock(mainChain, search, pendChain, pendTargets[i], blockSize);
		pendTargets.erase(pendTargets.begin() + i);
		updateMainTargets(mainChain, mainTargets, blockSize);
		std::cout << "main after insertion" << std::endl;
		printVector(mainChain);	
	}
	/* std::cout << "pend after insertion" << std::endl;
	printVector(pendChain);
	std::cout << "main targets after insertion" << std::endl;
	printVector(mainTargets);
	std::cout << "pend targets after insertion" << std::endl;
	printVector(pendTargets); */
	//inserir o bloco inteiro no lugar correto
}

std::vector<int> mergeInsertionSort(std::vector<int> &v) {

	static size_t blockSize = 2; //quantos numeros cada par possui. eh o conjunto de dois elementos
	size_t	elementSize = blockSize / 2; //quantos numeros cada elemento de um bloco possui
	std::cout << "blockSize = " << blockSize << std::endl;
	
	if (blockSize > v.size()) {
		blockSize /= 2;
		return v;
	}
	size_t pos = elementSize - 1;
	size_t pos_to_compare = pos + elementSize;
	while(pos_to_compare < v.size()) {
		if (v[pos] > v[pos_to_compare]) {
			swapBlocks(v, pos, pos_to_compare, blockSize);
		}
		pos += blockSize;
		pos_to_compare = pos + elementSize;
	}
	/* std::cout << "vetor dos a's" << std::endl;
	printVector(a); */
	blockSize *= 2;
	printVector(v);
	mergeInsertionSort(v);
	std::cout << "blockSize = " << blockSize << std::endl;
	std::vector<int> mainChain, pendChain, a, b;
	mainChain = initMainChain(v, a, b, blockSize);
	pendChain = initPendChain(v, b, blockSize);
	//update a and b vectors
	//updateAB(a, b, mainChain, pendChain, blockSize);
	std::cout << "main" << std::endl;
	printVector(mainChain);
	std::cout << "pend" << std::endl;
	printVector(pendChain);
	insertPendToMain(mainChain, pendChain, a, b, blockSize);
	//verificar se ha algum elemento perdido em v, que nao esta na main, e adiciona-lo(s)
	for (size_t i = mainChain.size(); i < v.size(); i++)
		mainChain.push_back(v[i]);
	blockSize /= 2;
	v = mainChain;
	return v;
}


int main() {
	std::cout << "BEFORE" << std::endl;
	std::vector<int> v = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	//std::vector<int> v = {7, 14, 11, 2, 9, 13, 3};
	printVector(v);

	v = mergeInsertionSort(v);
	std::cout << "AFTER" << std::endl;
	printVector(v);

	/* std::cout << "DEPOIS DE TODA A RECURSIVIDADE" << std::endl;
	printVector(v); */
	/* std::cout << "BEFORE" << std::endl;
	printVector(v);
	ft_swap(v, 3, 7, 8);
	std::cout << "AFTER" << std::endl;
	printVector(v); */
}