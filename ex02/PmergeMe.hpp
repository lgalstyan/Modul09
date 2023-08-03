#ifndef PMERGEAME
#define PMERGEAME

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN   "\x1B[32m"
#define RED		"\033[31m"

#include <iostream>
#include <string>
#include <vector>
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
        int check_num(char *);
    private:
        std::vector<int> _vect;
        struct timeval _t_vector_start;
        struct timeval _t_vector_finish;
        struct timeval _t_list_start;
        struct timeval _t_list_finish;
};



double	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000000) + (time.tv_usec));
}

#endif