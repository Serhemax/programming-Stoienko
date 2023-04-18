#include <stdlib.h>
#include <check.h>

START_TEST(test_sum)
{
    int a = 1;
    int b = 2;
    int expected = 3;
    int actual = 2;
    ck_assert_int_eq(actual, expected);
}

START_TEST(test_mul)
{
    int a = 2;
    int b = 3;
    int expected = 6;
    int actual = 6;
    ck_assert_int_eq(actual, expected);
}

Suite *calc_suite(void)
{
    Suite *s;
    TCase *tc_core;
    
    s = suite_create("Calculator");
    
    tc_core = tcase_create("Core");
    
    tcase_add_test(tc_core, test_sum);
    tcase_add_test(tc_core, test_mul);
    suite_add_tcase(s, tc_core);

    return s;
}

/* 
 * clang test_check.c lib.c -lcheck -o test 
 */
 
int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;
    
    s = calc_suite();
    sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
