#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_diagonalElements_sort) {
  unsigned int size = 3;

  int **mas = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < (int)size; i++) {
    *(mas + i) = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < (int)size; j++) {
      *(*(mas + i) + j) = 0;
    }
  }

  *(*(mas + 0) + 0) = 10;
  *(*(mas + 1) + 1) = 5;
  *(*(mas + 2) + 2) = 15;

  int *actual = (int *)malloc(size * sizeof(int));
  diagonalElements(size, mas, actual);
  int *expected = (int *)malloc(size * sizeof(int));
  *(expected + 0) = 5;
  *(expected + 1) = 10;
  *(expected + 2) = 15;

  for (int i = 0; i < (int)size; i++) {
    ck_assert_int_eq(expected[i], actual[i]);
  }
  free(mas);
  free(actual);
}
END_TEST

START_TEST(test_diagonalElements_alleq) {
  unsigned int size = 3;

  int **mas = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < (int)size; i++) {
    *(mas + i) = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < (int)size; j++) {
      *(*(mas + i) + j) = 0;
    }
  }

  *(*(mas + 0) + 0) = 1;
  *(*(mas + 1) + 1) = 1;
  *(*(mas + 2) + 2) = 1;

  int *expected = (int *)malloc(size * sizeof(int));
  *(expected + 0) = 1;
  *(expected + 1) = 1;
  *(expected + 2) = 1;

  int *actual = (int *)malloc(size * sizeof(int));
  diagonalElements(size, mas, actual);

  for (int i = 0; i < (int)size; i++) {
    ck_assert_int_eq(expected[i], actual[i]);
  }

  for (int i = 0; i < (int)size; i++) {
    free(*(mas + i));
  }
  free(mas);
  free(actual);
}
END_TEST

START_TEST(test_diagonalElements_twoeq) {
  unsigned int size = 3;

  int **mas = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < (int)size; i++) {
    *(mas + i) = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < (int)size; j++) {
      *(*(mas + i) + j) = 0;
    }
  }

  *(*(mas + 0) + 0) = 1;
  *(*(mas + 1) + 1) = 1;
  *(*(mas + 2) + 2) = 0;

  int *expected = (int *)malloc(size * sizeof(int));
  *(expected + 0) = 0;
  *(expected + 1) = 1;
  *(expected + 2) = 1;

  int *actual = (int *)malloc(size * sizeof(int));
  diagonalElements(size, mas, actual);

  for (int i = 0; i < (int)size; i++) {
    ck_assert_int_eq(expected[i], actual[i]);
  }

  for (int i = 0; i < (int)size; i++) {
    free(*(mas + i));
  }
  free(mas);
  free(actual);
}
END_TEST

START_TEST(test_diagonalElements_all_null) {
  unsigned int size = 3;

  int **mas = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < (int)size; i++) {
    *(mas + i) = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < (int)size; j++) {
      *(*(mas + i) + j) = 0;
    }
  }

  *(*(mas + 0) + 0) = 0;
  *(*(mas + 1) + 1) = 0;
  *(*(mas + 2) + 2) = 0;

  int *expected = (int *)malloc(size * sizeof(int));
  *(expected + 0) = 0;
  *(expected + 1) = 0;
  *(expected + 2) = 0;

  int *actual = (int *)malloc(size * sizeof(int));
  diagonalElements(size, mas, actual);

  for (int i = 0; i < (int)size; i++) {
    ck_assert_int_eq(expected[i], actual[i]);
  }

  for (int i = 0; i < (int)size; i++) {
    free(*(mas + i));
  }
  free(mas);
  free(actual);
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab11");

  tcase_add_test(tc_core, test_diagonalElements_sort);
  tcase_add_test(tc_core, test_diagonalElements_twoeq);
  tcase_add_test(tc_core, test_diagonalElements_alleq);
  tcase_add_test(tc_core, test_diagonalElements_all_null);
  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
