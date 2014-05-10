#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>
using namespace std;

class MergeSort;

class MergeSort
{
    public:

    MergeSort();
    MergeSort(const int* list, int length);
    ~MergeSort();

    friend ostream& operator<< (ostream& os, const MergeSort& ms);
    int& operator[] (const int index);

    int& length (void);
    void swap (int element1, int element2);

    void merge (int start, int mid, int end);
    void mergesort (void);
    void _mergesort (int start, int end);


    private:

    int* list;
    int len;
};

ostream& operator<< (ostream& os, const MergeSort& ms);
#endif
