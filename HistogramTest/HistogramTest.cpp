#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/Histogram.h"

namespace HistogramTest 
{
	TEST(HistogramTest, TestNameHistogram) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestPositive) {
		Histogram histogram;
		EXPECT_NO_THROW(histogram.generateRanges(5, 5));
	}
	TEST(HistogramTest, TestNegativeStep) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(-5, 5));
	}
	TEST(HistogramTest, TestNegativeAmount) {
		Histogram histogram;
		EXPECT_ANY_THROW(histogram.generateRanges(5, -5));
	}

	bool areWordsInGivenRange(std::map<Range, int> testMap, Range range, int expected) {
		return testMap[range] == expected;
	}

	TEST(HistogramTest, TestInGivenRange) {
		Histogram histogram;
		std::vector<Range> ranges = histogram.generateRanges(3, 6);
		std::map<Range, int> testMap = histogram.generate("gowno dupa sraka", ranges);
		EXPECT_TRUE(areWordsInGivenRange(testMap, ranges[1], 3));
		//EXPECT_TRUE(histogram.generate("example", range));
	}

	TEST(HistogramTest, TestOutOfRange) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> testMap = histogram.generate("a b c", range);
		EXPECT_NO_THROW();
	}

	TEST(HistogramTest, TestEmptyText) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 6);
		std::map<Range, int> testMap = histogram.generate("a b c", range);
		EXPECT_NO_THROW(histogram.generate("example", range));
	}

	TEST(histogramtest, testHistogramMultipleTimes) {
		Histogram histogram;
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("a", range);
		histogram.generate("b", range);
		EXPECT_NO_THROW(histogram.generate("example", range));
	}

	TEST(HistogramTest, TestCallingBeforeGeneratingHistogram) {
		Histogram histogram;
		auto exampleMap = histogram.getHistogram();
		EXPECT_TRUE(exampleMap.empty());
	}

	TEST(HistogramTest, TestCallingAfterGeneratingHistogram) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("siema", range);
		auto exampleMap = histogram.getHistogram();
		EXPECT_FALSE(exampleMap.empty());
	}

	TEST(HistogramTest, TestCallingAfterMultipleCalls) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		histogram.generate("siema", range);
		auto histogram1 = histogram.getHistogram();
		histogram.generate("colka", range);
		auto histogram2 = histogram.getHistogram();
		EXPECT_TRUE(histogram1.empty() == false && histogram2.empty() == false);
	}

	TEST(HistogramTest, TestHistogramBeforeGenerating) {
		Histogram histogram = Histogram();
		EXPECT_EQ(histogram.draw(), "");
	}

	TEST(HistogramTest, TestHistogramAfterGenerating) {
		Histogram histogram = Histogram();
		std::vector<Range>range = histogram.generateRanges(1, 5);
		auto histogram1 = histogram.generate("siema", range);

		EXPECT_FALSE(histogram.draw().empty());
	}

	TEST(HistogramTest, TestGetMax) {

		Histogram histogram = Histogram();
		std::vector<Range>range = std::vector<Range>{ Range(0, 1),  Range(2, 3),  Range(4, 6),  Range(7, 10) };
		histogram.generate("siema nara kol eluw jesi spiu", range);

		EXPECT_EQ(histogram.getMax(), 5);
	}

	TEST(HistogramTest, TestGetMin) {

		Histogram histogram = Histogram();
		std::vector<Range>range = std::vector<Range>{ Range(0, 1),  Range(2, 3),  Range(4, 6),  Range(7, 10) };
		histogram.generate("siema nara kol eluw jesi spiu", range);

		EXPECT_EQ(histogram.getMin(), 1);
	}
}