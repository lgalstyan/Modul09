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

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& );
        PmergeMe& operator=(const PmergeMe& );
        ~PmergeMe();
        void init(int , char** );
        void fill_list(int , char **);
        void fill_vector(int , char **);
    private:
        void print_vect();
        void print_list();
        int check_num(char *);
    private:
        std::vector<int> _vect;
        std::list<int> _list;
        double _t_vector_start;
        double _t_vector_finish;
        double _t_list_start;
        double _t_list_finish;
        struct timeval _time;
};
double	get_current_time(struct timeval* );

#endif