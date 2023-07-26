#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <map>

enum errors
{
    DEFAULT = 0,
    NOT_POSITIVE = 1,
    BAD_INPUT = 2,
    TOO_LARGE = 3
};

class Bitcoin
{
    public:
        Bitcoin();
        Bitcoin(const Bitcoin& );
        Bitcoin& operator=(const Bitcoin& );
        ~Bitcoin();
    
        void takeInputData(const std::string& ); // read each line and call parsDate for each line
        void takeDatabase(const std::string& ); // read each line and call parsDate for each line
    
    private:
        std::map<std::string, float> _database; 
        std::map<std::string, float, errors> _inputData;

    private:
        void parseInputData(std::string ); //parse line into => date(string): Year-Month-Day, value(float): 0 and 1000 //hendl error in this function using print, errors started with DEFAULT
        void parseDataBase(std::string ); //parse line into => date(string): Year-Month-Day and value(float): 0 and 1000 //hendl error in this function using print
        void change_value(); //search for the closest date and returns the corresponding value

};

#endif