#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Range.h"
#define FROM 1
#define TO 3

namespace RangeTest
{
	// Example, feel free to modify
	struct RangeTestF : public ::testing::Test {
		RangeTestF() {
			range1 = new Range(FROM, TO);
		}

		~RangeTestF()
		{
			delete range1;
		}

		Range* range1;
	};

	TEST_F(RangeTestF, TestIsInRange) {
		std::string word = "xx";
		EXPECT_TRUE(range1->isInRange(word));
	}
	TEST_F(RangeTestF, TestEqualsFrom) {
		std::string word = "x";
		EXPECT_TRUE(range1->isInRange(word));
	}
	TEST_F(RangeTestF, TestOutOfRange) {
		std::string word = "";
		EXPECT_FALSE(range1->isInRange(word));
	}

}
