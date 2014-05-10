#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>
#include "TestMergeSort.h"


int
main ()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( TestMergeSort::suite() );
    runner.run();
    return 0;
}
