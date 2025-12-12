#include "unity.h"
#include <math.h>
#include "lib.h"

void setUp() {}
void tearDown() {}

void test_func14()
{
    double pi = acos(-1.0);
    TEST_ASSERT_EQUAL_FLOAT(7.0, func14(2, pi / 2, 4, 0));
    TEST_ASSERT_EQUAL_FLOAT(-4.0, func14(1, 0, 9, pi));
    TEST_ASSERT_EQUAL_FLOAT(-5.0, func14(-2, pi / 6, 1, pi / 2));
}

void test_func18()
{
    double pi = acos(-1.0);
    TEST_ASSERT_FLOAT_WITHIN(1e-3, 1.386, func18(2, 3, 0, 4));
    TEST_ASSERT_EQUAL_FLOAT(-3.0, func18(1, 0, pi / 2, 9));
    TEST_ASSERT_FLOAT_WITHIN(1e-3, -0.693, func18(0, 1, pi, 0));
}

void test_func3()
{
    double pi = acos(-1.0);
    TEST_ASSERT_FLOAT_WITHIN(1e-3, 2.718, func3(1, 0, 2, 0, pi / 4));
    TEST_ASSERT_EQUAL_FLOAT(0.0, func3(0, pi / 2, 1, pi / 3, pi / 6));
    TEST_ASSERT_FLOAT_WITHIN(1e-2, 8.11, func3(2, pi, 3, 0, pi / 3));
}

void test_func8()
{
    double pi = acos(-1.0);
    TEST_ASSERT_EQUAL_FLOAT(6.0, func8(2, 0, 1, 4, pi / 4));
    TEST_ASSERT_FLOAT_WITHIN(1e-2, -1.46, func8(1, pi / 2, 2, 9, pi / 3));
    TEST_ASSERT_EQUAL_FLOAT(0.0, func8(0, 0, 0, 1, pi / 2));
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_func14);
    RUN_TEST(test_func18);
    RUN_TEST(test_func3);
    RUN_TEST(test_func8);
    return UNITY_END();
}