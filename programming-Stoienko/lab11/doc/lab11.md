## Лабораторна робота №11
####Тема: Вступ до показчиків

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:** 
Дано масив масивів з N * N цілих чисел. Елементи головної діагоналі записати в одновимірний масив, отриманий масив упорядкувати за зростанням.

**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
lib.c / lib.h / main.c

 - Принцип оботи:
1)  виділення пам'яті для масива та матриці.
2)  робиться присвоєння матриці.
3)  До масиву записуємо діагональ матриці та потім робиимо сортування цього масиву
5)  виведення масиву на консоль.
6)  очищення виділеної пам'яті.


- **Перелік вхідних даних:**

 - size – розмір матриці та масива

 - **mas – матриця

 - *diagmas – масивб який будемо заповнювати

- **Дослідження результатів роботи програми** 

   У функції main заповнили матрицю та додали їй на місці [1][1] число 10, щоб у результаті вийшло у діагоналі 0 10 4 6 8. Після сортування у результаті повинно вийти 0 4 6 8 10.

•	**Перевіримо роботу функції за допомогою функції printf()**:
```
	serhii@mojavirtualka:~/tnp/programing-Stoienko/lab11$ dist/main.bin 
0 4 6 8 10

```
**Як бачимо, результати співпадають з реальними матрицями, тому функція знаходження відсортованної матриці працює**.

** Також зробимо тест **

```
serhii@mojavirtualka:~/tnp/programing-Stoienko/lab11$ dist/test.bin 
Running suite(s): Programing
100%: Checks: 4, Failures: 0, Errors: 0
test/test.c:29:P:lab11:test_diagonalElements_sort:0: Passed
test/test.c:97:P:lab11:test_diagonalElements_twoeq:0: Passed
test/test.c:61:P:lab11:test_diagonalElements_alleq:0: Passed
test/test.c:133:P:lab11:test_diagonalElements_all_null:0: Passed

serhii@mojavirtualka:~/tnp/programing-Stoienko/lab11$ make test
...
/home/serhii/tnp/programing-Stoienko/lab11/src/lib.c          13                 0   100.00%           2                 0   100.00%          17                 0   100.00%           8                 0   100.00%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                         13                 0   100.00%           2                 0   100.00%          17                 0   100.00%           8                 0   100.00%

```



**Структура проекту лабораторної роботи**:

        └── lab11
    ├── Doxyfile
    ├── Makefile
    ├── README.md
    ├── doc
    │   └── lab11.md
    ├── test
    │   └── test.c
    └── src
        ├── lib.c
        ├── lib.h
        └── main.c

 **Висновки**: при виконанні лабораторної роботи були набуті навички роботи з показчиками та роботи з тестами.


**Код проекту**:


** main.c : **
```
/**
  @mainpage
  Лабораторна робота №11
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 16-04-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main() {
  unsigned int size = 5;

  int **mas = (int **)malloc(size * sizeof(int *));
  for (int i = 0; i < (int)size; i++) {
    *(mas + i) = (int *)malloc(size * sizeof(int));
    for (int j = 0; j < (int)size; j++) {
      *(*(mas + i) + j) = i + j; // initialize with some values
    }
  }

  *(*(mas + 1) + 1) = 10;

  int *diagmas = (int *)malloc(size * sizeof(int));
  diagonalElements(size, mas, diagmas);

  for (unsigned int i = 0; i < size; i++) {
    printf("%d ", *(diagmas + i));
  }

  for (unsigned int i = 0; i < size; i++) {
    free(*(mas + i));
  }
  free(mas);
  free(diagmas);

  return 0;
}
```

** lib.c **

```
/**
 * @file lib.c
 * @brief
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include "lib.h"

void diagonalElements(unsigned int size, int **mas, int *diagmas) {
  for (unsigned int i = 0; i < size; i++) {
    *(diagmas + i) = *(*(mas + i) + i);
  }
  bubbleSort(diagmas, size);
}

void bubbleSort(int *arr, unsigned int size) {
  for (unsigned int i = 0; i < size - 1; i++) {
    for (unsigned int j = 0; j < size - i - 1; j++) {
      if (*(arr + j) > *(arr + j + 1)) {
        // swap arr[j] and arr[j+1]
        int temp = *(arr + j);
        *(arr + j) = *(arr + j + 1);
        *(arr + j + 1) = temp;
      }
    }
  }
}
```

**lib.h**

```
/**
 * @file lib.h
 * @brief
 *
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include <stdio.h>
#include <stdlib.h>

/**
        @brief Функція eлементи головної діагоналі масивa N*N записує в
   одновимірний масив, отриманий масив упорядкoвує за зростанням.

        @param size - Розмір
        @param **mas - масив з N * N цілих чисел
        @param *diagmas - Масив, який будемо заповнювати
*/

void diagonalElements(unsigned int size, int **mas, int *diagmas);

/**
        @brief Функція cортування BubbleSort

        @param n - Розмір
        @param *arr - масив
*/
void bubbleSort(int *arr, unsigned int size);
```

**test.c**

```
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
```

