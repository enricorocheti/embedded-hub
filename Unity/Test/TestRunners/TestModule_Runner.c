/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum)            \
    {                                              \
        Unity.CurrentTestName = #TestFunc;         \
        Unity.CurrentTestLineNumber = TestLineNum; \
        Unity.NumberOfTests++;                     \
        if (TEST_PROTECT())                        \
        {                                          \
            setUp();                               \
            TestFunc();                            \
        }                                          \
        if (TEST_PROTECT())                        \
        {                                          \
            tearDown();                            \
        }                                          \
        UnityConcludeTest();                       \
    }

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

#include "Module.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void Test_ModuleInit(void);
extern void Test_ModuleDeinit(void);
extern void Test_SetGetModuleParameter(void);
extern void Test_SetGetModuleWrongParameter(void);

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
    tearDown();
    setUp();
}

/*=======MAIN=====*/
int main(void)
{
    UnityBegin("Test/TestModule.c");

    RUN_TEST(Test_ModuleInit, 14);
    RUN_TEST(Test_ModuleDeinit, 23);
    RUN_TEST(Test_SetGetModuleParameter, 35);
    RUN_TEST(Test_SetGetModuleWrongParameter, 55);
    
    return (UnityEnd());
}
