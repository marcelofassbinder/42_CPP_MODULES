#include <iostream>
#include <vector>
#include <algorithm>

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

void	ft_swap(std::vector<int> &v, size_t pos, size_t pos_to_change, size_t blockSize) {

	std::vector<int> p1;
	std::vector<int> p2;

	size_t i = pos - (blockSize / 2) + 1;
	std::cout << "i = " << i << std::endl;
	while (i <= pos) {
		p1.push_back(v[i]);
		i++;
	}
	i = pos_to_change - (blockSize / 2) + 1;
	std::cout << "i = " << i << std::endl;
	while (i <= pos_to_change) {
		p2.push_back(v[i]);
		i++;
	}
	printVector(p1);
	printVector(p2);
	std::vector<int>::iterator firstPairBeg = (std::find(v.begin(), v.end(), v[pos]) - (blockSize / 2) + 1);
	std::vector<int>::iterator secondPairEnd = std::find(v.begin(), v.end(), v[pos_to_change]);
	std::cout << "firstPairBeg = " << *firstPairBeg << std::endl;
	std::cout << "SecondPairEnd = " << *secondPairEnd << std::endl;
	v.erase(firstPairBeg, secondPairEnd + 1);
	std::cout << "passou pelo erase" << std::endl;
	printVector(v);
	std::vector<int>::iterator it = firstPairBeg;
	i = 0;
	while (i < p1.size()) {
		std::cout << "it = " << *it << std::endl;
		v.insert(it, p1[i]);
		std::cout << "inseriu o " << p1[i] << std::endl;
		printVector(v);
		i++;
		it++;
	}
	it = std::find(v.begin(), v.end(), p1[0]);
	i = 0;
	while (i < p2.size()) {
	std::cout << "it = " << *it << std::endl;
		v.insert(it, p2[i]);
		std::cout << "inseriu o " << p2[i] << std::endl;
		printVector(v);
		i++;
		it++;
	}
}

void	swapBlocks(std::vector<int> &v, int pos, int pos_to_swap, int blockSize) {

	for(int i = 0; i < blockSize / 2; i++) {
		std::swap(v[pos - i], v[pos_to_swap - i]);
	}
}


std::vector<int> mergeInsertionSort(std::vector<int> &v) {

	static size_t blockSize = 2; //quantos numeros cada par possui
	
	std::cout << "blockSize = " << blockSize << std::endl;

	if (blockSize > (v.size() / 2))
		return v;
	size_t pos = (blockSize / 2) - 1;
	size_t pos_to_compare = 0;
	while(pos_to_compare < v.size()) {
		pos_to_compare = pos + blockSize / 2; 
		if (v[pos] > v[pos_to_compare])
			swapBlocks(v, pos, pos_to_compare, blockSize);
		pos += blockSize;
	}
	blockSize *= 2;
	mergeInsertionSort(v);
	std::cout << "DEPOIS DE TODA A RECURSIVIDADE" << std::endl;
	printVector(v);
	return v;

}

int main() {

	std::vector<int> v = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
	mergeInsertionSort(v);
	/* std::cout << "DEPOIS DE TODA A RECURSIVIDADE" << std::endl;
	printVector(v); */
	/* std::cout << "BEFORE" << std::endl;
	printVector(v);
	ft_swap(v, 3, 7, 8);
	std::cout << "AFTER" << std::endl;
	printVector(v); */
}