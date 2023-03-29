#include "pch.h"
#include "../CNumberSequence.h"

TEST(CNumberSequenceTests, InitSequenceFromInitilizerList)
{
	//Arrange
	const CNumberSequence seq{1, 3, 5, 7};

	//Act

	//Assert
	EXPECT_EQ(4, seq.GetCount());
	EXPECT_EQ(1, seq.ElementAt(0));
	EXPECT_EQ(3, seq.ElementAt(1));
	EXPECT_EQ(5, seq.ElementAt(2));
	EXPECT_EQ(7, seq.ElementAt(3));
}
