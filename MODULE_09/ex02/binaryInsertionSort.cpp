
#include <iostream>
#include <vector>
#include <algorithm>

//supondo que ja temos um vector ordenado e queremos inserir toInsert na posicao correta

//iterar o array do segundo ao ultimo elemento

int binarySearch(std::vector<int> &v, int toSearch) {

	int size, posLow, posHigh, posMid;

	size = v.size();
	posLow = 0;
	posMid = size / 2;
	posHigh = size - 1;
	while(posLow <= posHigh) {
		posMid = posLow + ((posHigh - posLow) / 2);
		if (toSearch == v[posMid]) {
			return posMid;
		}
		if (toSearch > v[posMid]) {
			posLow = posMid + 1;
		}
		if (toSearch < v[posMid]) {
			posHigh = posMid - 1;
		}
	}
	return -1;
}


/* void	binaryInsertionSort(std::vector<int> &v, int toInsert) {


} */

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

int main() {

	std::vector<int> a = {1, 4, 7, 10};
	std::vector<int>::iterator it = std::lower_bound(a.begin(), a.end(), 8);
	a.insert(it, 8);
	printVector(a);
	/* std::vector<int> a = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
	printVector(a);
	int pos, search;
	search = 2;
	pos = binarySearch(a, search);
	std::cout << "o numero " << search << " esta na posicao " << pos << std::endl; */
}