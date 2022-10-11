// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "../HistogramLibrary/TextReader.h"
#include "../HistogramLibrary/Histogram.h"

int main()
{
    std::string fileName = "text.txt";
    TextReader reader = TextReader(fileName);
    std::string chapter = reader.read();
        
    Histogram histogram = Histogram();

    std::cout << "words length histogram with generated ranges:" << std::endl;
    std::vector<Range> ranges = histogram.generateRanges(3, 5);
    histogram.generate(chapter, ranges);
    std::cout << histogram.draw() << std::endl;

    std::cout <<"words length histogram with specified ranges:" << std::endl;
    histogram = Histogram();
    ranges = std::vector<Range>{  Range(0, 1),  Range(2, 3),  Range(4, 6),  Range(7, 10) };
    histogram.generate(chapter, ranges);
    std::cout << histogram.draw() << std::endl;

    std::cout << "words length normalized histogram with specified ranges:" << std::endl;
    histogram =  Histogram();
    ranges =  std::vector<Range>{  Range(0, 1),  Range(2, 3),  Range(4, 6),  Range(7, 10) };
    histogram.generate(chapter, ranges);
    histogram.normalize();
    std::cout << histogram.draw() << std::endl;
}
