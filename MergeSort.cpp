#include <iostream>
#include <cmath>
#include "MergeSort.h"

using namespace std;

MergeSort::MergeSort()
{
    list = new int[0];
    len = 0;
}

MergeSort::MergeSort (const int* t, int length)
{
    if (t) {
        len = length;
        list = new int[len];
        for (int i = 0; i < length; i++)
            list[i] = t[i];
    }
    else {
        list = new int[0];
        len = 0;
    }
}

MergeSort::~MergeSort()
{
    delete[] list;
}

ostream& 
operator<< (ostream& os, const MergeSort& ms)
{
    if (ms.len >= 1)
        os << ms.list[0];

    for (int i = 1; i < ms.len; i++)
        os << ", " << ms.list[i];

    os << endl;
    return os;
}

int& 
MergeSort::operator[] (const int index)
{
    return list[index];
}

int& 
MergeSort::length (void)
{
    return len;
}

void print(int *l, int len)
{
    for (int i = 0; i < len; i++)
        cout << l[i] << " ";
    cout << endl;
}

void 
MergeSort::merge (int start, int mid, int end)
{
    int sorted[end+1];
    for (int i = start, left = start, right = mid; (left < mid || right <= end); i++)
    {
        if (left < mid && right <= end)
            sorted[i] = (list[left] <= list[right]) ? list[left++] : list[right++];
        else if (left < mid)
            sorted[i] = list[left++];
        else if (right <= end)
            sorted[i] = list[right++];
    } 

    for (int i = start; i <= end; i++)
        list[i] = sorted[i];
}


void
MergeSort::_mergesort (int start, int end)
{
    int mid = floor( (end - start)/2 ) + start;

    if (start + 1 == end) {
        if (list[start] > list[end])
            swap(start, end); 
    }
    if (start < end && start != mid) {
        _mergesort( start, mid );
        _mergesort( mid, end );
        merge( start, mid, end );
    }
}


void
MergeSort::mergesort ()
{
    _mergesort( 0, len-1 );
}


void
MergeSort::swap (int element1, int element2)
{
    int temp = list[element1];
    list[element1] = list[element2];
    list[element2] = temp;
}
