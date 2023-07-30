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
        void change();

    private:
        std::map<int, float> _database;
        std::string _fname; 

    private:
        void takeInputData(const std::string& ); // read each line and call parseInputData() for each line
        void takeDatabase(); // read each line and call parsDatebase() for each line
        void parseInputData(std::string& ); //parse line into => date(string): Year-Month-Day, value(float): 0 and 1000 //hendl error in this function using print, errors started with DEFAULT
        void parseDataBase(std::string& ); //parse line into => date(string): Year-Month-Day and value(float): 0 and 1000 //hendl error in this function using print
        bool IsValidDate(int year, int month, int day);
        bool isLeapYear(int year);
        std::pair<int, float> checkLow(const std::pair<int, float> & );
        int toInt(std::istringstream& );
        void change_one_elem(const std::pair<int, float> &, const std::string& );

        class ConvertFailedException : std::exception
        {
            public:
                const char * what() const throw();
        };
};

#endif