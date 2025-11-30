#include "unity.h"
#include <stdlib.h>

int sum_up_tri();
int *sum_col();
int count_more_average();
double interquartile_range();

void setUp() {}
void tearDown() {}

void test_sum_up_tri()
{
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    TEST_ASSERT_EQUAL_INT(26, sum_up_tri(3, m));
}

void test_sum_col()
{
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int *res = sum_col(3, m);
    TEST_ASSERT_NOT_NULL(res);
    TEST_ASSERT_EQUAL_INT(12, res[0]);
    TEST_ASSERT_EQUAL_INT(15, res[1]);
    TEST_ASSERT_EQUAL_INT(18, res[2]);

    free(res);
}

void test_count_more_average()
{
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    TEST_ASSERT_EQUAL_INT(4, count_more_average(3, m));
}

void test_interquartile_range()
{
    int m[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    TEST_ASSERT_FLOAT_WITHIN(0.0001, 5.0, interquartile_range(3, m));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_sum_up_tri);
    RUN_TEST(test_sum_col);
    RUN_TEST(test_count_more_average);
    RUN_TEST(test_interquartile_range);

    return UNITY_END();
}
