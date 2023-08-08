#ifndef PMERGEAME_HPP
#define PMERGEAME_HPP

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& );
        PmergeMe& operator=(const PmergeMe& );
        ~PmergeMe();
        void sorting(int , char** );

    private:
        void fill_list(int , char **);
        void fill_vector(int , char **);
        void print_sorted();
        void print_unsorted(int argc, char **argv);
        int check_num(char *);
        bool areAllDigits(const std::string& );
        double	get_current_time(struct timeval* );

    private:
        std::vector<int> _vect;
        std::list<int> _list;
        struct timeval _time;
        double _t_vector_start;
        double _t_vector_finish;
        double _t_list_start;
        double _t_list_finish;
};

template<typename Data>
void sort_insertion(Data vec_list)
{
    for (Data::iterator step = vec_list.begin(); step != vec_list.end(); ++step) 
    {
        Data::iterator key = step;
        Data::iterator j = step - 1;

        while (*key < *j && j >= 0)
        {
            j + 1 = j;
            --j;
        }
        j + 1 = key;
  }
}

#endif