#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>

class Bitcoin
{
    public:
        Bitcoin();
        Bitcoin(const std::string& );
        Bitcoin(const Bitcoin& );
        Bitcoin& operator=(const Bitcoin& );
        ~Bitcoin();
        void print();

    private:
        std::map<int, float> _database; 
        std::map<int, float> _inputData;
        std::map<std::string, float> _resultDate; 

    private:
        void takeInputData(const std::string& ); // read each line and call parseInputData() for each line
        void takeDatabase(); // read each line and call parsDatebase() for each line
        void parseInputData(std::string& ); //parse line into => date(string): Year-Month-Day, value(float): 0 and 1000 //hendl error in this function using print, errors started with DEFAULT
        void parseDataBase(std::string& ); //parse line into => date(string): Year-Month-Day and value(float): 0 and 1000 //hendl error in this function using print
        void change_value(); //search for the closest date and returns the corresponding value
        bool IsValidDate(int year, int month, int day);
        bool isLeapYear(int year);
        float exact_value(std::map<int, float>::iterator& ); //if exact value is exist return true and change _inputData map value, else if dosnt exist return false;
        std::map<int, float>::iterator checkLow(std::map<int, float>::iterator iter);
        int toInt(std::istringstream& );

        class ConvertFailedException : std::exception
        {
            public:
                const char * what() const throw();
        };
};

#endif