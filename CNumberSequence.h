#pragma once

#include <initializer_list>

class CNumberSequence
{
	struct Entry
	{
		Entry *Next;
		int Value;
	};

	size_t Count;
	Entry* Head = nullptr;
	Entry* Tail = nullptr;

public:
	CNumberSequence();
	CNumberSequence(std::initializer_list<int> numbers);

	~CNumberSequence();

	void Add(int number);
	void Add(const int *numbers, size_t offset, size_t count);
	void Add(const int *numbers, size_t count);
	void Add(const CNumberSequence& seq);

	size_t GetCount() const;

	int ElementAt(size_t idx) const;
	int operator[](size_t idx) const;

	CNumberSequence& operator<<(int number);
	CNumberSequence& operator+(int number);

	static CNumberSequence Union(const CNumberSequence& seq1, const CNumberSequence& seq2);
	CNumberSequence operator+(const CNumberSequence& seq2) const;
};
