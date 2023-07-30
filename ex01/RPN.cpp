#include "RPN.hpp"

RPN::RPN() : _input("unknown"){}

RPN::RPN(char *inp)
{
    std::string _input(inp);
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN &rhs)
{
    if (this != &rhs)
    {
        _memStack = rhs._memStack;
        _input = rhs._input;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::is_valid_number(std::string::const_iterator it)
{
    if (std::isdigit(static_cast<unsigned char>(*it)) && static_cast<int>(*it) < 10)
    {
        std::cout << RED << "❌Error : argument will always be less than 10"  << RESET << std::endl;
        return false;
    }
    if (std::isdigit(static_cast<unsigned char>(*it)))
        return true;
    return false;
}

void RPN::calculate()
{
    if (_input == "unknown")
        std::cerr << RED << "Error: have not any parametr\n" << RESET;
    fillstacks();
}

bool RPN::is_operator(std::string::const_iterator it)
{
    if (*it == '-' || *it == '/' || *it == '*' || *it == '+')
        return true;
    return false;
}

void RPN::fillstacks()
{
    std::string::const_iterator it;
    int res_print = 0;
    for (it = _input.begin(); it != _input.end(); ++it)
    {
        if (std::isspace(static_cast<unsigned char>(*it)) && it + 1 != _input.end())
            ++it;
        else if (is_valid_number(it))
            _memStack.push(static_cast<int>(*it));
        else if (is_operator(it))
        {
            int val1 = _memStack.top();
            _memStack.pop();
            int val2 = _memStack.top();
            _memStack.pop();
            switch (*it)
            {
            case '+':
                _memStack.push(val2 + val1);
                break;
            case '-':
                _memStack.push(val2 - val1);
                break;
            case '*':
                _memStack.push(val2 * val1);
                break;
            case '/':
                _memStack.push(val2 / val1);
                break;
            }
        }
        else
            std::cout << RED << "❌Error : invalid number"  << RESET << std::endl;
    }
    std::cout << BLUE << "Result is: " << res_print << std::endl << RESET;
}

