// Classwork2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CNumberSequence.h"

int main()
{
	{
		int seqqq[] = {1,2,3};
		const CNumberSequence seq1{{1, 2, 3, 4, 5, 6, 7}};
		const CNumberSequence seq2{};

		auto seq3 = CNumberSequence::Union(seq1, seq2);
	}

	std::cout << "Hello World!\n";
}
