#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_dig)
{
	char *input_data = "we have 23 potions and 21 poisons";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));
	*(expected + 0) = 2;
	*(expected + 1) = 3;
	*(expected + 2) = 2;
	*(expected + 3) = 1;

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_digits(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST
START_TEST(test_dig_null)
{
	char *input_data = "";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_digits(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST
START_TEST(test_dig_nol)
{
	char *input_data = "Hi, we have 0 apples:')";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));
	*(expected + 0) = 0;

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_digits(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST
START_TEST(test_num)
{
	char *input_data = "we have 23 potions and 21 poisons";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));
	*(expected + 0) = 23;
	*(expected + 1) = 21;

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_numbers(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST
START_TEST(test_num_nol)
{
	char *input_data = "Hi, we have 0 apples:')";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));
	*(expected + 0) = 0;

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_numbers(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST
START_TEST(test_num_null)
{
	char *input_data = "";
	char *input_data_with_null =
		(char *)malloc((strlen(input_data) + 1) * sizeof(char));
	strcpy(input_data_with_null, input_data);
	const size_t input_len = strlen(input_data);
	int *expected = (int *)malloc(input_len * sizeof(int));

	int *actual = (int *)malloc(input_len * sizeof(int));
	get_numbers(input_data_with_null, actual);

	for (int i = 0; i < (int)input_len; i++) {
		ck_assert_int_eq(*(expected + i), *(actual + i));
	}
	free(expected);
	free(actual);
	free(input_data_with_null);
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab13");

	tcase_add_test(tc_core, test_dig);
	tcase_add_test(tc_core, test_dig_null);

	tcase_add_test(tc_core, test_num);
	tcase_add_test(tc_core, test_num_null);

	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
