#include "TextReader.h"
#include <fstream>
#include <vector>

TextReader::TextReader(std::string fileName) : fileName(fileName)
{}

std::string TextReader::read()
{
    std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
    std::ifstream::pos_type fileSize = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    std::vector<char> bytes(fileSize);
    ifs.read(bytes.data(), fileSize);

    return std::string(bytes.data(), fileSize);
}
