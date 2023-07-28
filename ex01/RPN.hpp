#ifndef RPN
#define RPN

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"

#include <iostream>

class RPN
{
    public:
        RPN();
        RPN(const RPN &);
        RPN& operator=(const RPN &);
        ~RPN();
        void fillstacks(std::string &line);

    private:
        std::stack<int> _memStack;
        std::stack<int> _operStack;
    
    private:
        bool is_operator(std::string::const_iterator );
        bool is_valid_number(std::string::const_iterator );

};

#endif