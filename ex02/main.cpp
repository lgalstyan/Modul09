#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << RED << "Error: invalid arguments\n" << RESET;
        return (2);
    }
    PmergeMe sort;
    sort.sorting(argc, argv);
    return 0;
}