#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "MutantStack.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main()
{
	{
		printHeader("Test: MutanStack");
		std::cout << SMYELLOW << "Creating MutantStack \"mstack\" with 2 elements..." << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack.top(): " << SMGREEN << mstack.top() << RESET << std::endl;
		std::cout << SMYELLOW << "Using pop() to remove top element..." << RESET << std::endl;
		mstack.pop();
		std::cout << "mstack size is: " << SMGREEN << mstack.size() << RESET << std::endl;
		std::cout << SMYELLOW << "Adding 4 elements to mstack..." << RESET << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << SMYELLOW << "Printing mstack elements through iterator..." << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		printHeader("Test: list");
		std::cout << SMYELLOW << "Creating list \"li\" with 2 elements..." << RESET << std::endl;
		std::list<int> li;
		li.push_back(5);
		li.push_back(17);
		std::cout << "li.back(): " << SMGREEN << li.back() << RESET << std::endl;
		std::cout << SMYELLOW << "Using pop_back() to remove last element..." << RESET << std::endl;
		li.pop_back();
		std::cout << "li size is: " << SMGREEN << li.size() << RESET << std::endl;
		std::cout << SMYELLOW << "Adding 4 elements to mstack..." << RESET << std::endl;
		li.push_back(3);
		li.push_back(5);
		li.push_back(737);
		li.push_back(0);
		std::list<int>::iterator it = li.begin();
		std::list<int>::iterator ite = li.end();
		++it;
		--it;
		std::cout << SMYELLOW << "Printing li elements through iterator..." << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(li);
	}
	{
		printHeader("Test: const_iterator");
		std::cout << SMYELLOW << "Creating MutantStack \"mstack\" with 6 elements..." << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "mstack size is: " << SMGREEN << mstack.size() << RESET << std::endl;

		std::cout << SMYELLOW << "Creating const reference from \"mstack\"..." << RESET << std::endl;
		const MutantStack<int> &constMstack = mstack;

		MutantStack<int>::const_iterator it = constMstack.begin();
		MutantStack<int>::const_iterator ite = constMstack.end();

		std::cout << SMYELLOW << "Printing mstack elements through const_iterator..." << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		printHeader("Test: reverse_iterator");
		std::cout << SMYELLOW << "Creating MutantStack \"mstack\" with 6 elements..." << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "mstack size is: " << SMGREEN << mstack.size() << RESET << std::endl;

		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();

		std::cout << SMYELLOW << "Printing mstack elements through reverse_iterator..." << RESET << std::endl;
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
		std::stack<int> s(mstack);
	}
	{
		printHeader("Test: const_reverse_iterator");
		std::cout << SMYELLOW << "Creating MutantStack \"mstack\" with 6 elements..." << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "mstack size is: " << SMGREEN << mstack.size() << RESET << std::endl;
		std::cout << SMYELLOW << "Creating const reference from \"mstack\"..." << RESET << std::endl;
		const MutantStack<int> &constMstack = mstack;

		MutantStack<int>::const_reverse_iterator it = constMstack.rbegin();
		MutantStack<int>::const_reverse_iterator ite = constMstack.rend();

		std::cout << SMYELLOW << "Printing mstack elements through const_iterator..." << RESET << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		printHeader("Test: Init MutantStack with deque && vector");
		std::cout << SMYELLOW << "Creating MutantStack \"first\" with default constructor (empty)..." << RESET << std::endl;
		MutantStack<int> first;
		std::cout << "size of first: " << SMGREEN << first.size() << RESET << std::endl;

		std::cout << SMYELLOW << "Creating deque \"mydeque\" with " << SMGREEN << "3" << SMYELLOW << " elements..." << RESET << std::endl;
		std::deque<int> mydeque (3,100);

		std::cout << SMYELLOW << "Creating MutantStack \"second\" with mydeque..." << RESET << std::endl;
		MutantStack<int> second (mydeque);
		std::cout << "size of second: " << SMGREEN << second.size() << RESET << std::endl;

		std::cout << SMYELLOW << "Creating MutantStack \"third\" with std::vector container (empty)..." << RESET << std::endl;
		MutantStack<int,std::vector<int> > third;
		std::cout << "size of third: " << SMGREEN << third.size() << RESET << std::endl;

		std::cout << SMYELLOW << "Creating vector \"myvector\" with " << SMGREEN << "2" << SMYELLOW << " elements..." << RESET << std::endl;
		std::vector<int> myvector (2,200);

		std::cout << SMYELLOW << "Creating MutantStack \"fourth\" with myvector..." << RESET << std::endl;
		MutantStack<int,std::vector<int> > fourth (myvector);
		std::cout << "size of fourth: " << SMGREEN << fourth.size() << RESET << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
