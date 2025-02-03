#include <iostream>
#include "iter.hpp"

int main() {

	int arrayInt[4] = {0, 2, 21, 7};

	iter(arrayInt, 4, changeToFortyTwo<int>);
}
