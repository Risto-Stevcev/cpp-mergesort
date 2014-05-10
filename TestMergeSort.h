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

    void setUp();
    void tearDown();
    void testLength();
    void testIndex();
    void testMerge();
    void testMergesort();

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
