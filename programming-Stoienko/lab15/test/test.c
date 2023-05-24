#include "../src/lib.h"
#include <stdlib.h>
#include <check.h>

START_TEST(test_read_birds)
{
	int num_birds;
	Bird *birds = read_bird("test_input.txt", &num_birds);

	ck_assert_int_eq(birds[0].is_ringed, 1);
	ck_assert_str_eq(birds[0].type, "журавель");
	ck_assert_int_eq(birds[0].age, 2);
	ck_assert_int_eq(birds[0].home.area, 100);
	ck_assert_int_eq(birds[0].home.height, 50);
	ck_assert_int_eq(birds[0].home.feeders, 2);
	ck_assert_int_eq(birds[0].home.has_nest, 1);
	ck_assert_str_eq(birds[0].gender, "чоловіча");

	ck_assert_int_eq(birds[1].is_ringed, 0);
	ck_assert_str_eq(birds[1].type, "гусак");
	ck_assert_int_eq(birds[1].age, 6);
	ck_assert_int_eq(birds[1].home.area, 200);
	ck_assert_int_eq(birds[1].home.height, 75);
	ck_assert_int_eq(birds[1].home.feeders, 1);
	ck_assert_int_eq(birds[1].home.has_nest, 0);
	ck_assert_str_eq(birds[1].gender, "чоловіча");

	ck_assert_int_eq(birds[2].is_ringed, 1);
	ck_assert_str_eq(birds[2].type, "сорока");
	ck_assert_int_eq(birds[2].age, 8);
	ck_assert_int_eq(birds[2].home.area, 150);
	ck_assert_int_eq(birds[2].home.height, 60);
	ck_assert_int_eq(birds[2].home.feeders, 3);
	ck_assert_int_eq(birds[2].home.has_nest, 1);
	ck_assert_str_eq(birds[2].gender, "жіноча");

	for (int i = 0; i < 3; i++) {
		free(birds[i].type);
		free(birds[i].gender);
	}
}
END_TEST
START_TEST(test_num_birds)
{
	int num_birds;
	Bird *birds = read_bird("test_input.txt", &num_birds);

	ck_assert_int_eq(num_birds, 3);

	for (int i = 0; i < 3; i++) {
		free(birds[i].type);
		free(birds[i].gender);
	}
}
END_TEST
START_TEST(test_get_gender_ratio)
{
	int num_birds;
	Bird *birds = read_bird("test_input.txt", &num_birds);

	ck_assert_float_eq_tol(get_gender_ratio(birds, num_birds), 1.0f / 3.0f * 100.0f, 0.01);

	for (int i = 0; i < 3; i++) {
		free(birds[i].type);
		free(birds[i].gender);
	}
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab15");

	tcase_add_test(tc_core, test_read_birds);
	tcase_add_test(tc_core, test_num_birds);
	tcase_add_test(tc_core, test_get_gender_ratio);

	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
