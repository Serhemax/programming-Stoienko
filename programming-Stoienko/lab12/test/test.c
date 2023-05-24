#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_inverse)
{
	unsigned int size = 2;

	float **mas = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(mas + i) = (float *)malloc(size * sizeof(float));
	}

	*(*(mas + 0) + 0) = 1;
	*(*(mas + 0) + 1) = 2;
	*(*(mas + 1) + 0) = 3;
	*(*(mas + 1) + 1) = 4;

	float **actual = inverse_matrix(mas, size);
	float **expected = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(expected + i) = (float *)malloc(size * sizeof(float));
	}
	*(*(expected + 0) + 0) = -2;
	*(*(expected + 0) + 1) = 1;
	*(*(expected + 1) + 0) = 1.5;
	*(*(expected + 1) + 1) = -0.5;

	for (int i = 0; i < (int)size; i++) {
		for (int j = 0; j < (int)size; j++) {
			ck_assert_float_eq_tol(expected[i][j], actual[i][j],
					       0.0001);
		}
	}
	free_matrix(mas, size);
	free_matrix(expected, size);
	free_matrix(actual, size);
}
END_TEST

START_TEST(test_inverse_diag)
{
	unsigned int size = 4;

	float **mas = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(mas + i) = (float *)malloc(size * sizeof(float));
		for (int j = 0; j < (int)size; j++) {
			if (i == j) {
				*(*(mas + i) + j) = 1.0;
			} else {
				*(*(mas + i) + j) = 0.0;
			}
		}
	}

	float **actual = inverse_matrix(mas, size);
	float **expected = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(expected + i) = (float *)malloc(size * sizeof(float));
		for (int j = 0; j < (int)size; j++) {
			if (i == j) {
				*(*(expected + i) + j) = 1.0;
			} else {
				*(*(expected + i) + j) = 0.0;
			}
		}
	}

	for (int i = 0; i < (int)size; i++) {
		for (int j = 0; j < (int)size; j++) {
			ck_assert_float_eq_tol(*(*(expected + i) + j),
					       *(*(actual + i) + j), 0.0001);
		}
	}
	free_matrix(mas, size);
	free_matrix(expected, size);
	free_matrix(actual, size);
}
END_TEST

START_TEST(test_inverse_null_det)
{
	unsigned int size = 2;

	float **mas = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(mas + i) = (float *)malloc(size * sizeof(float));
	}

	*(*(mas + 0) + 0) = 1;
	*(*(mas + 0) + 1) = 2;
	*(*(mas + 1) + 0) = 1;
	*(*(mas + 1) + 1) = 2;

	ck_assert_ptr_null(inverse_matrix(mas, size));
	free_matrix(mas, size);
}
END_TEST

START_TEST(test_inverse_one_by_one)
{
	unsigned int size = 1;

	float **mas = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(mas + i) = (float *)malloc(size * sizeof(float));
	}
	float **expected = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(expected + i) = (float *)malloc(size * sizeof(float));
	}

	*(*(mas + 0) + 0) = 1;

	*(*(expected + 0) + 0) = 1;

	float **actual = inverse_matrix(mas, size);

	for (int i = 0; i < (int)size; i++) {
		for (int j = 0; j < (int)size; j++) {
			ck_assert_float_eq_tol(*(*(expected + i) + j),
					       *(*(actual + i) + j), 0.0001);
		}
	}
	free_matrix(mas, size);
	free_matrix(expected, size);
	free_matrix(actual, size);
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab12");

	tcase_add_test(tc_core, test_inverse);
	tcase_add_test(tc_core, test_inverse_diag);
	tcase_add_test(tc_core, test_inverse_null_det);
	tcase_add_test(tc_core, test_inverse_one_by_one);

	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
