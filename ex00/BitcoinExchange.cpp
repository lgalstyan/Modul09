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

int Bitcoin::toInt(std::istringstream& str)
{
    int result = 0;
    std::string year;
    std::string month;
    std::string day;
    std::getline(str, year, '-');
    std::getline(str, month, '-');
    std::getline(str, day, '-');
    int iyear = atoi(year.c_str());
    int imonth = atoi(month.c_str());
    int iday = atoi(day.c_str());
    //2009-01-11,0
    if (!IsValidDate(iyear, imonth, iday))
        return (0);
    result = iyear * 10000 + imonth * 100 + iday;
    return result;
}

void Bitcoin::parseDataBase(std::string &inp_str)
{
    std::string part1;
    int tmp = 0;
    float part2;

    std::istringstream stream(inp_str);
    
    std::getline(stream, part1, ',');
    stream >> part2;
    if (stream.fail())
        throw ConvertFailedException(); 

    std::istringstream tmp_stream(part1);

    tmp = toInt(tmp_stream);
    if (tmp == 0)
        std::cout << "Error: bad database => " << inp_str; 
    _database.insert(std::make_pair(tmp, part2));
}

bool Bitcoin::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool Bitcoin::IsValidDate(int year, int month, int day)
{
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    static const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maxDays = daysInMonth[month];
    
    if (month == 2 && isLeapYear(year)) {
        maxDays = 29;
    }

    if (day > maxDays) {
        return false;
    }
    return true;
}

void Bitcoin::parseInputData(std::string &inp_str)
{
    std::string part1;
    std::string tmp_str;
    float part2 = 0.0f;
    int idate;

    std::istringstream stream(inp_str);
    
    if(std::getline(stream, part1, '|'))
        stream >> part2;
    
    std::istringstream tmp_stream(part1);

    idate = toInt(tmp_stream);

    std::cout << "in pars " << idate << " " << part2 << std::endl;

    _inputData.insert(std::make_pair(idate, part2));
}

float Bitcoin::exact_value(std::map<int, float>::iterator &elem)
{
    std::map<int, float>::const_iterator itdb;
    for (itdb = _database.begin(); itdb != _database.end(); ++itdb)
    {
        if (itdb->first == elem->first)
        {
            return itdb->second;
        }
    }
    return (-1.0f);
}

std::map<int, float>::iterator Bitcoin::checkLow(std::map<int, float>::iterator iter)
{
    std::map<int, float>::iterator it;
    std::cout << iter->first << " " << iter->second << std::endl;
    for(it = _database.begin(); it != _database.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return _database.end();
}

// std::cout << "aaaaaaaaa\n" ;
void Bitcoin::change_value()
{
    float res_val = 0.0f;
    std::string res_str = "";

    std::map<int, float>::iterator it;
    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        if (it->first == 0)
        {
            res_str = "Error: bad input => " + std::to_string(it->first) + "\n";
        }
        else if (it->second < 0)
        {
            res_str = "Error: not a positive number.";
        }
        else if (it->second > 1000)
        {
            res_str = "Error: too large a number.";
        }
        else
        {
            res_val = exact_value(it);
            if (res_val == -1.0f)
            {

                // chi gtnvel petq e ptrel aveli poqr amsativy.
            }
            else
            {
                res_str = it->first;
                res_val *= it->second;
                _resultDate.insert(std::make_pair(res_str, res_val));
                // veradarcrac arjeqy push_back() anel _resultDate map_um
            }
        }
    }
}

void Bitcoin::print()
{
    std::map<int, float>::iterator it;
    for (it = _inputData.begin(); it != _inputData.end(); ++it)
    {
        // if (it->first[0] == 'E')
        //     std::cout << it->first ;
        // else
        {
            std::cout << it->first << " => " << it->second << std::endl;
        }
    }
   
}

const char* Bitcoin::ConvertFailedException::what() const throw()
{
    return ("Exception: Conversion failed");
}
