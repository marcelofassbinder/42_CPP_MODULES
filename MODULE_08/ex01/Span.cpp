#include "Span.hpp"

Span::Span() : _limit(100){}

Span::Span(unsigned int N) : _limit(N){}

Span::Span(const Span &src) : _vector(src._vector), _limit(src._limit){}

Span& Span::operator=(const Span &src) {
	
	if(this != &src) {
		this->_limit = src._limit;
		this->_vector.clear();
		this->_vector = src._vector;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int newNumber) {
	
	if (this->_vector.size() < this->_limit)
		this->_vector.push_back(newNumber);
	else
		throw (std::out_of_range("Limit overflow"));
}

unsigned int	Span::shortestSpan() {
	
	if (this->_vector.size() <= 1)
		throw (std::out_of_range("The container must have more than 1 element"));
		
	std::vector<int> sorted_vector = this->_vector;
	std::sort(sorted_vector.begin(), sorted_vector.end());

	int shortest = std::numeric_limits<int>::max();
	
	for (std::vector<int>::iterator it = sorted_vector.begin(); it != sorted_vector.end(); ++it) {
		if (it == sorted_vector.begin())
			continue;
		if (std::abs(*it - *(it - 1)) < shortest) {
			shortest = std::abs(*it - *(it - 1));
		}
	}
	return shortest;
}

unsigned int	Span::longestSpan() {

	if (this->_vector.size() <= 1)
		throw (std::out_of_range("The container must have more than 1 element"));

	std::vector<int>::iterator min = std::min_element(this->_vector.begin(), this->_vector.end());
	std::vector<int>::iterator max = std::max_element(this->_vector.begin(), this->_vector.end());
	
	return (std::abs(*max - *min));

}

void	Span::fill(std::vector<int>::iterator beg, std::vector<int>::iterator end) {
	
	while(beg != end) {
		if (this->_vector.size() == this->_limit)
			throw (std::out_of_range("Limit overflow"));
		this->_vector.push_back(*beg);
		beg++;
	}
}

std::vector<int> &Span::getVector(void) {
	return this->_vector;
}

void	Span::print() {
	
	int i = 0;
	for(std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it) {
		std::cout << GREEN << "vector[" << i << "] = " << BOLD << *it << RESET << std::endl;
		i++;  
	}
}
