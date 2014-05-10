#ifndef __TESTMERGESORT_H__
#define __TESTMERGESORT_H__
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestFixture.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "MergeSort.h"

using namespace std;

class TestMergeSort : public CppUnit::TestFixture
{
    public:


    void 
    setUp ()
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
    tearDown () 
    {
        delete mergesort;
        delete[] list;
        delete[] sorted_list;
    }

    void 
    testLength ()
    {
        CPPUNIT_ASSERT( mergesort->length() == list_len );
    }

    void 
    testIndex ()
    {
        for (int i = 0; i < list_len; i++) {
          CPPUNIT_ASSERT( list[i] != 0 );
          CPPUNIT_ASSERT( (*mergesort)[i] == list[i] );
        }
    }

    void
    testMerge ()
    {
        int left[] = {25260, 29649, 54044};
        int right[] = {2995, 14108, 15232};
        int merged[6] = {0};

        mergesort->merge( left, 3, right, 3, merged );

        for (int i = 0; i < 6; i++)
            CPPUNIT_ASSERT( merged[i] == sorted_list[i] );
    }

    void
    testMergesort ()
    {
        int len = mergesort->length();

        for (int i = 0; i < len; i++)
            CPPUNIT_ASSERT( (*mergesort)[i] == list[i] );

        mergesort->mergesort();

        for (int i = 0; i < len; i++)
            CPPUNIT_ASSERT( (*mergesort)[i] == sorted_list[i] );
    }

    static 
    CppUnit::Test *suite ()
    {
        CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "TestMergeSort" );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestMergeSort>( 
                                       "testLength", 
                                       &TestMergeSort::testLength ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestMergeSort>( 
                                       "testIndex", 
                                       &TestMergeSort::testIndex ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestMergeSort>( 
                                       "testMerge", 
                                       &TestMergeSort::testMerge ) );
        suiteOfTests->addTest( new CppUnit::TestCaller<TestMergeSort>( 
                                       "testMergesort", 
                                       &TestMergeSort::testMergesort ) );
        return suiteOfTests;
    }

    private:

    MergeSort *mergesort;
    int *list;
    int *sorted_list;
    int list_len;
};
#endif
