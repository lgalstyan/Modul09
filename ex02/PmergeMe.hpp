#ifndef PMERGEAME_HPP
#define PMERGEAME_HPP

#define RESET	"\033[0m"
#define BLUE	"\033[1;34m"
#define GREEN "\x1B[32m"
#define RED		"\033[31m"
#define LIMIT 5

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
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
		void fill_deque(int , char **);
		void fill_vector(int , char **);
		void print_sorted();
		void print_unsorted(int argc, char **argv);
		int check_num(char *);
		bool areAllDigits(const std::string& );
		double	get_current_time(struct timeval* );

	private:
		std::vector<int> _vect;
		std::deque<int> _deque;
		struct timeval _time;
		double _t_vector_start;
		double _t_vector_finish;
		double _t_deque_start;
		double _t_deque_finish;
};

template<typename Data>
void print_vector(Data vec_deque)
{
	for (typename Data::iterator step = vec_deque.begin(); step != vec_deque.end(); ++step) 
	{
		std::cout << *step << ' ';
	}
	std::cout << std::endl;
}

template<typename Data>
void sort_insertion(Data &vec_deque)
{
  typename Data::iterator it1, it2;

	for (it1 = vec_deque.begin() + 1; it1 <= vec_deque.end(); ++it1)
  {
			int key = *it1;
			it2 = it1;
			while (it2 > vec_deque.begin() && key < *(it2 - 1))
      {
				*it2 = *(it2 - 1);
				--it2;
			}
			*it2 = key;
	}
}

template<typename Data>
void merge(Data &arr, int left, int midl, int right)
{
	int n1 = midl - left + 1;
	int n2 = right - midl;

	Data L[n1];
	Data M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];

	for (int j = 0; j < n2; j++)
		M[j] = arr[midl + 1 + j];

	int i, j, k;
	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
  {
		if (L[i] < M[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}
  
	while (i < n1)
  {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
  {
		arr[k] = M[j];
		j++;
		k++;
	}
}

template<typename Data>
void mergeSort(Data &arr, int l, int r) {
	if (r - l <= LIMIT) {
		insertionSort(arr.begin() + l, arr.begin() + r);
	} else {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

#endif