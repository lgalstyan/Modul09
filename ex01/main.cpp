#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED << "Error: takes one parameter\n" << RESET;
        return (2);
    }
    RPN calculator(argv[1]);
    calculator.fillstack();
}