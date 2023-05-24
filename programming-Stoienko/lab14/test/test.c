#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_create_sine_wave)
{
	FILE *fp = fopen("test.txt", "w");
	create_wave(5, 45, '#', fp);
	fclose(fp);
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab14");

	tcase_add_test(tc_core, test_create_sine_wave);

	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
