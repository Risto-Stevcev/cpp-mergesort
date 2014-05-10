#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>
using namespace std;

class MergeSort;

class MergeSort
{
    public:

    MergeSort();
    MergeSort(const int*, int);
    ~MergeSort();

    friend ostream& operator<< (ostream&, const MergeSort&);
    int& operator[] (const int index);

    int& length (void);

    void merge (int *, int, int *, int, int *);
    void mergesort (void);
    int *_mergesort (int *, int);


    private:

    int* list;
    int len;
};

ostream& operator<< (ostream&, const MergeSort&);
void print_arr(int *, int);
#endif
