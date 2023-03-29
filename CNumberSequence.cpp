#include "CNumberSequence.h"

CNumberSequence::CNumberSequence() : Count{0}
{
}

CNumberSequence::CNumberSequence(const std::initializer_list<int> numbers) : CNumberSequence{}
{
	for (const auto& number : numbers)
	{
		Add(number);
	}
}

CNumberSequence::~CNumberSequence()
{
	if (!Head)
		return;

	const Entry* current = Head;

	do
	{
		const Entry* tmp = current->Next;

		delete current;

		current = tmp;
	}
	while (current);

	Head = Tail = nullptr;
}

int CNumberSequence::ElementAt(size_t idx) const
{
	if (idx >= Count)
		return 0;

	auto current = Head;
	while (idx--)
	{
		current = current->Next;
	}

	return current->Value;
}

void CNumberSequence::Add(const int number)
{
	const auto entry = new Entry{nullptr, number};

	if (!Tail)
	{
		Head = Tail = entry;
	}
	else
	{
		Tail->Next = entry;

		Tail = entry;
	}

	++Count;
}


void CNumberSequence::Add(const int* numbers, const size_t offset, const size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		Add(numbers[offset + i]);
	}
}

void CNumberSequence::Add(const int* numbers, const size_t count)
{
	Add(numbers, 0, count);
}

void CNumberSequence::Add(const CNumberSequence& seq)
{
	auto current = seq.Head;

	while (current)
	{
		Add(current->Value);

		current = current->Next;
	}
}

size_t CNumberSequence::GetCount() const
{
	return Count;
}

CNumberSequence& CNumberSequence::operator<<(const int number)
{
	Add(number);

	return *this;
}

CNumberSequence& CNumberSequence::operator+(const int number)
{
	Add(number);

	return *this;
}

int CNumberSequence::operator[](const size_t idx) const
{
	return ElementAt(idx);
}

CNumberSequence CNumberSequence::Union(const CNumberSequence& seq1, const CNumberSequence& seq2)
{
	CNumberSequence seq;
	seq.Add(seq1);
	seq.Add(seq2);

	return seq;
}

CNumberSequence CNumberSequence::operator+(const CNumberSequence& seq2) const
{
	return Union(*this, seq2);
}
