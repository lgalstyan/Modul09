#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _vect = rhs._vect;
        _list = rhs._list;
        _t_vector_start = rhs._t_vector_start;
        _t_vector_finish = rhs._t_vector_finish;
        _t_list_start = rhs._t_list_start;
        _t_list_finish = rhs._t_list_finish;
    }
    return (*this);
}

PmergeMe::~PmergeMe(){}

void PmergeMe::init(int argc, char **argv)
{
    // for vector
    _t_vector_start = get_current_time(&_time);
    fill_vector(argc, argv);
    //TODO write sort using vector
    print_vect();
    std::cout << std::endl;
    _t_vector_finish = get_current_time(&_time);


    //for list
    _t_list_start = get_current_time(&_time);
    fill_list(argc, argv);
    print_list();
    std::cout << std::endl;
    // //TODO write sort using list
    _t_list_finish = get_current_time(&_time);

    std::cout << "Time to process a range of " << argc << " elements with std::vector : " << (_t_vector_finish - _t_vector_start) / 1000 << " us\n";
    std::cout << "Time to process a range of " << argc << " elements with std::list : " << (_t_list_finish - _t_list_start) / 1000 << " us\n";
}

bool PmergeMe::areAllDigits(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    if (*it == '+')
        ++it;
    for (; it != str.end(); ++it)
    {
        if (!isdigit(*it)) {
            return false;
        }
    }
    return true;
}

int PmergeMe::check_num(char *num)
{
    int res = -1;
    std::string str(num);
    std::string str1(num);
    std::istringstream stream(str);
    std::istringstream stream1(str);
    
    std::getline(stream, str, ' ');
    std::istringstream convert(str);
    convert >> res;
    if (stream.fail() || (res == 0 && str[0] != '0') || !areAllDigits(str))
        return -1;
    if (stream.fail())
    {
        return -1;
    }
    return res;
}

void PmergeMe::fill_list(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        int tmp = check_num(argv[i]);
        if (tmp < 0)
        {
            std::cerr << RED << "❌Error : invalid input!\n" << RESET;
            exit(1);
        }   
        else 
        {
            _list.push_back(tmp);
        }
    }
}

void PmergeMe::fill_vector(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
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

void PmergeMe::print_list()
{
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
}

void PmergeMe::print_vect()
{
    for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); ++it) {
        std::cout << *it << " ";
    }
}

// PmergeMe::

double	get_current_time(struct timeval *time)
{
	gettimeofday(time, NULL);
    return ((time->tv_sec * 1000000) + (time->tv_usec));
}