#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(){}

Bitcoin::Bitcoin(const std::string& inp_fname)
{
    takeDatabase();
    takeInputData(inp_fname);
    change_value();
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
        // std::cout << "aaaaaaaaa  " << input <<std::endl;

    //check if form is correct Year-Month-Day
    int year, month, day;
    int result = std::sscanf(input.c_str(), "%d-%d-%d", &year, &month, &day);
    if (month > 12 || month < 1 || day > 31 || day < 1)
        return false;
    return (result == 3);
}

void Bitcoin::parseInputData(std::string &inp_str)
{
    std::string part1;
    std::string tmp_str;
    float part2 = 0.0f;

    std::istringstream stream(inp_str);
    
    if(std::getline(stream, part1, '|'))
        stream >> part2;
    
    if (stream.str().empty() || !IsValidDate(part1))
    {
        tmp_str = part1;
        part1 = "Error: bad input => " + tmp_str + "\n";
    }
    else if (part2 < 0)
    {
        part1 = "Error: not a positive number.";
    }
    else if (part2 > 1000)
    {
        part1 = "Error: too large a number.";
    }
        // std::cout << "data " << part1 << " value " << part2 <<std::endl;
    _inputData.insert(std::make_pair(part1, part2));
}

bool Bitcoin::exact_value(std::map<std::string, float>::iterator &elem)
{
    std::map<std::string, float>::const_iterator itdb;
    for (itdb = _database.begin(); itdb != _database.end(); ++itdb)
    {
        if (itdb->first == elem->first)
        {
            // elem->second = itdb->second * elem->second;
            return true;
        }
    }
    return false;
}

std::map<std::string, float>::iterator Bitcoin::checkLow(std::map<std::string, float>::iterator iter)
{
    
}

// std::cout << "aaaaaaaaa\n" ;
void Bitcoin::change_value()
{
    float new_val = 0.0f;

    std::map<std::string, float>::iterator it;
    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        // std::cout << it->first << " => " << it->second << " = " ;
        if (exact_value(it))
        {
            std::map<std::string, float>::const_iterator itdb;
            for (itdb = _database.begin(); itdb != _database.end(); ++itdb)
            {
                if (itdb->first == it->first)
                {
                    new_val = itdb->second * it->second;
                    break;
                }
            }
        }
        else
        {
            std::map<std::string, float>::const_iterator itdb;
            itdb = checkLow(it);
            if (itdb == _database.begin())
            {
                std::cout << "No lower date found in the database." << std::endl;
            }
            else
            {
                new_val = it->second * itdb->second;
            }
        }
        std::cout << new_val << std::endl;
    }
}

void Bitcoin::print()
{
    std::map<std::string, float>::iterator it;
    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        if (it->first[0] == 'E')
            std::cout << it->first ;
        else
        {
            std::cout << it->first << " => " << it->second << std::endl;
        }
    }
   
}

const char* Bitcoin::ConvertFailedException::what() const throw()
{
    return ("Exception: Conversion failed");
}
