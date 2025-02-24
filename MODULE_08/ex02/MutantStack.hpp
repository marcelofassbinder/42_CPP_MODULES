#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

template<typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container> {
		
	public:
		//	ORTHODOX CANONICAL FORM
		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack &src): std::stack<T, Container>(src) {};
		MutantStack& operator=(const MutantStack &src) {
			if (this != &src) {
				this->c.clear();
				this->c = src.c;
			}
			return *this;
		};
		~MutantStack() {};

		//	TYPEDEFS (ALIAS)
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		
		//	ITERATOR
		iterator	begin(void) {
			return this->c.begin();
		}
		iterator	end(void) {
			return this->c.end();
		}

		//	CONST ITERATOR
		const_iterator	cbegin(void) {
			return this->c.begin();
		}
		const_iterator	cend(void) {
			return this->c.end();
		}

		//	REVERSE ITERATOR
		reverse_iterator	rbegin(void) {
			return this->c.rbegin();
		}

		reverse_iterator	rend(void) {
			return this->c.rend();
		}

		//	CONST REVERSE ITERATOR
		const_reverse_iterator	crbegin(void) {
			return this->c.crbegin();
		}

		const_reverse_iterator	crend(void) {
			return this->c.crend();
		}
		
		void	print(void){
			iterator it;
			
			for(it = this->c.begin(); it != this->c.end(); it++) {
				std::cout << "Mutant Stack -> " << *it << std::endl;
			}
	}
};

#endif