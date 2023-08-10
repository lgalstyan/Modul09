#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file.\n";
        return 2;
    }
    try
    {
        Bitcoin btc(argv[1]);
        btc.change();
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET << '\n';
    }
    return 0;
}