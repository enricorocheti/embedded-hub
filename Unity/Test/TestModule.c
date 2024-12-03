#include "Module.h"
#include "unity.h"

void setUp(void)
{
    /* This is run before EACH TEST */
}

void tearDown(void)
{
    
}

void Test_ModuleInit(void)
{
    Module module;

    TEST_ASSERT_EQUAL(0, Module_Init(&module));
    TEST_ASSERT_EQUAL(1, module.IsInitialized);
    TEST_ASSERT_NOT_EQUAL(0, Module_Init(NULL));
}

void Test_ModuleDeinit(void)
{
    Module module;

    TEST_ASSERT_EQUAL(0, Module_Init(&module));
    TEST_ASSERT_EQUAL(1, module.IsInitialized);

    TEST_ASSERT_EQUAL(0, Module_Deinit(&module));
    TEST_ASSERT_EQUAL(0, module.IsInitialized);
    TEST_ASSERT_NOT_EQUAL(0, Module_Deinit(NULL));
}

void Test_SetGetModuleParameter(void)
{
    Module module;
    uint8_t value;

    TEST_ASSERT_EQUAL(0, Module_Init(&module));
    TEST_ASSERT_EQUAL(1, module.IsInitialized);

    TEST_ASSERT_EQUAL(0, Module_SetParameter(&module, 10, 0x01));
    TEST_ASSERT_EQUAL(0, Module_SetParameter(&module, 11, 0x10));

    TEST_ASSERT_EQUAL(0, Module_GetParameter(&module, 10, &value));
    TEST_ASSERT_EQUAL_HEX8(0x01, value);
    TEST_ASSERT_EQUAL(1, Module_GetParameter(&module, 11, &value));
    TEST_ASSERT_EQUAL_HEX8(0x10, value);

    TEST_ASSERT_EQUAL(0, Module_Deinit(&module));
    TEST_ASSERT_EQUAL(0, module.IsInitialized);
}

void Test_SetGetModuleWrongParameter(void)
{
    Module module;
    uint8_t value;

    TEST_ASSERT_EQUAL(0, Module_Init(&module));
    TEST_ASSERT_EQUAL(1, module.IsInitialized);

    TEST_ASSERT_NOT_EQUAL(0, Module_SetParameter(NULL, 0, 0x00));
    TEST_ASSERT_NOT_EQUAL(0, Module_SetParameter(&module, 16, 0x00));

    TEST_ASSERT_NOT_EQUAL(0, Module_GetParameter(NULL, 0, &value));
    TEST_ASSERT_NOT_EQUAL(0, Module_GetParameter(&module, 16, &value));

    TEST_ASSERT_EQUAL(0, Module_Deinit(&module));
    TEST_ASSERT_EQUAL(0, module.IsInitialized);

    TEST_ASSERT_NOT_EQUAL(0, Module_SetParameter(&module, 0, 0x00));
    TEST_ASSERT_NOT_EQUAL(0, Module_GetParameter(&module, 0, &value));
}