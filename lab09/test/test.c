#include "../src/lib.h"
#include <check.h>

START_TEST(test_nsd)
{
#define DATA_SIZE_NSD 3
	int input_data_a[] = { 50, 51, 25 };
	int input_data_b[] = { 100, 100, 80 };
	int expected_values[] = { 50, 1, 5 };

	for (int i = 0; i < DATA_SIZE_NSD; i++) {
		int actual_value = find_nsd(input_data_a[i], input_data_b[i]);
		ck_assert_int_eq(expected_values[i], actual_value);
	}
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab09");

	tcase_add_test(tc_core, test_nsd);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
