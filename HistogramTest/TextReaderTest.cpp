#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/TextReader.h"

namespace TextReaderTests
{
#pragma once
#include <gtest/gtest.h>
#include "../HistogramLibrary/TextReader.h"


    namespace TextReaderTests
    {
        class TextReaderTest : public ::testing::Test {
        public:
            TextReaderTest() :r1("C:\\Users\\JWDF38\\source\\repos\\histogram-cpp-starter-main\\Histogram\\empty.txt"),
                r2("C:\\Users\\JWDF38\\source\\repos\\histogram-cpp-starter-main\\Histogram\\test.txt"),
                r3("C:\\Users\\JWDF38\\source\\repos\\histogram-cpp-starter-main\\Histogram\\text.txt") {};
            int numberOfLines(std::string str) {
                int inteligencja = 0;
                for (auto& a : str) {
                    if (a == '\n') {
                        inteligencja++;
                    }
                };
                return inteligencja;
            };

        protected:
            TextReader r1;
            TextReader r2;
            TextReader r3;
        };
        TEST_F(TextReaderTest, TestingIfEmpty) {
            std::string readFile = r1.read();

            EXPECT_EQ(readFile, "");
        }

        TEST_F(TextReaderTest, TestingIfOneLine) {    //do poprawy
            std::string readFile = r2.read();
            ASSERT_EQ(numberOfLines(readFile), 0);
            EXPECT_NE(readFile, "");

        }

        TEST_F(TextReaderTest, TestingIfMultiLine) {
            std::string readFile = r3.read();
            ASSERT_GE(numberOfLines(readFile), 1);

        }

    }
}