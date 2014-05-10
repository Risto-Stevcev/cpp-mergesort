#include <fstream>
#include <iostream>
#include <cstdlib>
#include "MergeSort.h"
using namespace std;

int 
main (int argc, char *argv[]) 
{
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " [list file] [list size]" << endl;
        return -1;
    }

    char buffer[256];
    ifstream myfile( argv[1] );

    int length = atoi( argv[2] );
    int *list = new int[length];

    for (int i = 0; i < length; i++) {
      myfile.getline( buffer, 100 );
      list[i] = atoi( buffer );
    }

    MergeSort *ms = new MergeSort( list, length );
    ms->mergesort();
    cout << *ms << endl;

    delete[] list;
    delete ms;
    return 0;
}
