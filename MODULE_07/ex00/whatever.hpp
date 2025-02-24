#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>

void soma(T &a, T &b) {
	std::cout << a + b << std::endl;
}

template <typename T>

void	swap(T &a, T &b) {
	T swap;

	swap = a;
	a = b;
	b = swap;
}

template <typename T>

T& min(T &a, T&b) {

	if (a < b)
		return a;
	return b;
}

template <typename T>

T& max(T &a, T&b) {

	if (a > b)
		return a;
	return b;
}

#endif