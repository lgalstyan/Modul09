#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::Bitcoin(const std::string& inp_fname)
{
    takeDatabase();
    takeInputData(inp_fname);
}

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
    
void Bitcoin::takeInputData(const std::string& fname)
{
    std::string strtmp;
    std::ifstream file(fname);
    if (!file)
    {
        std::cout << "Error: " << fname << " file not found\n";
    }
    std::getline(file, strtmp);
    while (std::getline(file, strtmp))
    {
        if (!file.eof())
        {
            parseInputData(strtmp);
        }
        else
            break;
    }
}

void Bitcoin::takeDatabase()
{
    std::string strtmp;
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cout << "Error: data.csv file not found\n";
    }
    std::getline(file, strtmp);
    while (std::getline(file, strtmp))
    {
        if (!file.eof())
        {
            parseDataBase(strtmp);
        }
        else
            break;
    }
}

void Bitcoin::parseDataBase(std::string &inp_str)
{
    std::string part1;
    float part2;

    std::istringstream stream(inp_str);
    
    std::getline(stream, part1, ',');
    stream >> part2;
    if (stream.fail())
    {
        throw ConvertFailedException(); 
    }
    _database.insert(std::make_pair(part1, part2));
}

bool Bitcoin::IsValidDate(const std::string &input)
{
    //USING CHATGPT must check

    //check if form is correct Year-Month-Day
    int year, month, day;
    int result = std::sscanf(input.c_str(), "%d-%d-%d", &year, &month, &day);
    return (result == 3);
}

void Bitcoin::parseInputData(std::string &inp_str)
{
    std::string part1;
    std::string tmp_str;
    float part2;

    std::istringstream stream(inp_str);
    
    std::getline(stream, part1, '|');
    stream >> part2;
    if (stream.str().empty() || !IsValidDate(part1))
    {
        tmp_str = part1;
        part1 = "Error: bad input => " + tmp_str;
    }
    else if (part2 < 0)
    {
        part1 = "Error: not a positive number.";
    }
    else if (part2 > 1000)
    {
        part1 = "Error: too large a number.";
    }
    _inputData.insert(std::make_pair(part1, part2));
}

bool Bitcoin::exact_value(std::map<std::string, float>::iterator &elem)
{
    std::map<std::string, float>::const_iterator it;
    for (it = _database.begin(); it != _database.end(); ++it)
    {
        if (it->first == elem->first)
        {
            elem->second = it->second * elem->second;
            return true;
        }
    }
    return false;
}

void Bitcoin::change_value()
{
    std::map<std::string, float>::iterator it;
    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        if (!exact_value(it))
        {
            _database.lower_bound(it->first);//need to check
        }
    }
}

const char* Bitcoin::ConvertFailedException::what() const throw()
{
    return ("Exception: Conversion failed");
}
