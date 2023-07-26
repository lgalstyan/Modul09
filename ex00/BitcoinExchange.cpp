#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::Bitcoin(const Bitcoin& other)
{
    *this = other;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& rhs)
{
    if (this != &rhs)
    {
        _database = rhs._database;
        _inputData = rhs._inputData;
    }
    return *this;
}

Bitcoin::~Bitcoin() {}
    
void Bitcoin::takeData(const std::string& fname)
{
    std::ifstream file(fname);
    if (!file)
    {
        std::cout << "Error: " << fname << "file not found\n";
    }
}