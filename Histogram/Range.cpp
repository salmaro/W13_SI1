#include "Range.h"

Range::Range(int from, int to) : from(from), to(to) {}

bool Range::isInRange(std::string word)
{
    return word.size() >= from && word.size() <= to;
}

std::string Range::toString()
{
    return {std::to_string(from) +" - "+ std::to_string(to)};
}

