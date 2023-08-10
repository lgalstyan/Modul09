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

template<typename Data>
void merge(Data arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  Data L[n1];
  Data M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

template<typename Data>
void mergeSort(Data arr, int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

#endif