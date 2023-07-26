#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
        Bitcoin(const std::string& );
        Bitcoin(const Bitcoin& );
        Bitcoin& operator=(const Bitcoin& );
        ~Bitcoin();
    
    
    private:
        std::map<std::string, float> _database; 
        std::map<std::string, float, errors> _inputData;

    private:
        void takeInputData(const std::string& ); // read each line and call parseInputData() for each line
        void takeDatabase(); // read each line and call parsDatebase() for each line
        void parseInputData(std::string& ); //parse line into => date(string): Year-Month-Day, value(float): 0 and 1000 //hendl error in this function using print, errors started with DEFAULT
        void parseDataBase(std::string& ); //parse line into => date(string): Year-Month-Day and value(float): 0 and 1000 //hendl error in this function using print
        void change_value(); //search for the closest date and returns the corresponding value
        bool IsValidDate(const std::string &);

        class ConvertFailedException : std::exception
        {
            public:
                const char * what() const throw();
        };
};

#endif