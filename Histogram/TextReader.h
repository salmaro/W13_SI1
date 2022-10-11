#pragma once
#include <string>


class TextReader
{
public:
	TextReader(std::string fileName);
    virtual ~TextReader(){};
	std::string read();

private:
	std::string fileName;
};

