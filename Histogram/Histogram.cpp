#include "Histogram.h"
#include <stdexcept> 
#include <regex>

Histogram::Histogram()
{
    histogram = std::map<Range, int>();
}

std::map<Range, int> Histogram::getHistogram()
{
    return histogram;
}

std::vector<Range> Histogram::generateRanges(int step, int amount)
{
    if (step < 0) {
        throw new std::invalid_argument("Step must be positive.");
    }

    if (amount < 0) {
        throw new std::invalid_argument("Amount must be positive.");
    }

    std::vector<Range> ranges = std::vector<Range>();

    for (int i = 0; i < amount; i++) {
        ranges.push_back(Range(i * step + 1, i * step + step));
    }
    return ranges;
}

std::map<Range, int> Histogram::generate(const std::string text, std::vector<Range> ranges)
{
    histogram = std::map<Range, int>();
    if (text.empty()) {
        return histogram;
    }
    // remove punctuation and split by whitespace
    std::regex expression("[^a-zA-Z \\r?\\n]");
    std::vector<std::string> words;
    std::string clearedText = std::regex_replace(text, expression, "");
    std::string regexStr = " ";
    auto tokens = split(clearedText, regexStr);
    for (auto &item : tokens) {
        words.push_back(item);
    }

    for (auto &word : words) {
        for(auto range : ranges) {
            if (range.isInRange(word)) {
                histogram[range]++;
            }
        }
    }
    return histogram;
}

void Histogram::normalize() {
    //TODO: impelemnt normalization method
}

std::string Histogram::draw()
{
    std::string result;
    for (auto &entry : histogram) {
        int count = entry.second;
        Range range = entry.first;
        std::string line = range.toString() + "|" + std::string(count, '*');
        result += line + "\n";
    }
    return result;
}

std::vector<std::string> Histogram::split(const std::string str, const std::string regexStr)
{
    std::regex expression(regexStr);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), expression, -1),
                                  std::sregex_token_iterator());
    return list;
}