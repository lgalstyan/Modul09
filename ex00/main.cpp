#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return 2;
    }
    try
    {
        Bitcoin btc(argv[1]);
        // btc.print();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    return 0;
}