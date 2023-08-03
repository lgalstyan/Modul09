#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << RED <<"Error\n" << RESET;
        return (2);
    }
    PmergeMe sort;
    sort.init(argc, argv);
    return 0;
}