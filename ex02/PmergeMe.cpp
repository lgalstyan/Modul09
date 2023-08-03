#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& ){}

PmergeMe& PmergeMe::operator=(const PmergeMe& ){}

PmergeMe::~PmergeMe(){}

void PmergeMe::init(int argc, char **argv)
{
    //for vector
    gettimeofday(&_t_vector_start, 0);
    fill_vector(argc, argv);
    //TODO write sort using vector
    gettimeofday(&_t_vector_finish, 0);


    //for list
    gettimeofday(&_t_list_start, 0);
    fill_list(argc, argv);
    //TODO write sort using list
    gettimeofday(&_t_list_finish, 0);
}

int PmergeMe::check_num(char *num)
{
    std::string str(num);
    int res = 1;
    // if (str.find_last_of("0123456789") != std::string::npos)
    // {
    //     return true;
    // }
    std::string::const_iterator it;
    it = str.begin();
    while (it != str.end() && std::isspace(static_cast<unsigned char>(*it)))
        ++it;
    if (*it == '+')
        ++it;
    while (std::isdigit(*it))
        res = res * 10 + (*it); 
    return res;
}
void PmergeMe::fill_list(int argc, char **argv)
{
    for (unsigned int i = 1; i < argc; ++i)
    {
        int tmp = check_num(argv[i]);
        if (tmp < 0)
        {
            std::cerr << RED << "❌Error : invalid input!\n" << RESET;
            exit(1);
        }   
        else 
        {
            _vect.push_back(tmp);
        }
    }
}

void PmergeMe::fill_vector(int argc, char **argv)
{
    for (unsigned int i = 1; i < argc; ++i)
    {
        if (check_num(argv[i]))
        {

        }
        else 
        {

        }
    }
}


// PmergeMe::