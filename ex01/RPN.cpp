#inlcude "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN &rhs)
{
    //not done
    return *this;
}

RPN::~RPN() {}


bool RPN::is_operator(std::string::const_iterator it)
{
    if (it == '+' || it == '-' || it == '*' || it == '/')
        return true;
    return false;
}

bool RPN::is_valid_number(std::string::const_iterator it)
{
    if (std::isdigit(static_cast<unsigned char>(it)) && static_cast<int>(it) < 10)
    {
        std::cout << RED << "❌Error : argument will always be less than 10"  << RESET << std::endl;
        return false;
    }
    if (std::isdigit(static_cast<unsigned char>(it)))
        return true;
    return false;
}

void RPN::fillstacks(std::string &line)
{
    std::string::const_iterator it;

    for (it = line.begin(); it != line.end(); ++it)
    {
        if (std::isspace(static_cast<unsigned char>(it)) && it + 1 != line.end())
            ++it;
        else if (is_valid_number(it))
        {
            _memStack.push_back(it - '0');
        }
        else if (is_operator(it))
        {
            int val1 = _memStack.pop();
            int val2 = _memStack.pop();
            switch (*it)
            {
            case '+':
                _memStack.push_back(val2 + val1);
                break;
            case '-':
                _memStack.push_back(val2 - val1);
                break;
            case '*':
                _memStack.push_back(val2 * val1);
                break;
            case '/':
                _memStack.push_back(val2 / val1);
                break;
            }
        }
        else
            std::cout << RED << "❌Error : invalid number"  << RESET << std::endl;
    }
}

