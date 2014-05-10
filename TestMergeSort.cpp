#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include "TestMergeSort.h"


void 
TestMergeSort::setUp ()
{
    int __list[] = {25260, 29649, 54044, 2995, 14108, 15232};
    int __sorted_list[] = {2995, 14108, 15232, 25260, 29649, 54044};

    list_len = sizeof (__list)/sizeof(int);

    list = new int[list_len];
    sorted_list = new int[list_len];

    memcpy( list, __list, sizeof(int)*list_len );
    memcpy( sorted_list, __sorted_list, sizeof(int)*list_len );

    mergesort = new MergeSort( list, list_len );
}

void 
TestMergeSort::tearDown () 
{
    delete mergesort;
    delete[] list;
    delete[] sorted_list;
}

void 
TestMergeSort::testLength ()
{
    CPPUNIT_ASSERT( mergesort->length() == list_len );
}

void 
TestMergeSort::testIndex ()
{
    for (int i = 0; i < list_len; i++) {
      CPPUNIT_ASSERT( list[i] != 0 );
      CPPUNIT_ASSERT( (*mergesort)[i] == list[i] );
    }
}

void
TestMergeSort::testMerge ()
{
    int left[] = {25260, 29649, 54044};
    int right[] = {2995, 14108, 15232};
    int merged[6] = {0};

    mergesort->merge( left, 3, right, 3, merged );

    for (int i = 0; i < 6; i++)
        CPPUNIT_ASSERT( merged[i] == sorted_list[i] );
}

void
TestMergeSort::testMergesort ()
{
    int len = mergesort->length();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*mergesort)[i] == list[i] );

    mergesort->mergesort();

    for (int i = 0; i < len; i++)
        CPPUNIT_ASSERT( (*mergesort)[i] == sorted_list[i] );
}


int
main ()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestMergeSort::suite() );
    runner.run();
    return 0;
}
