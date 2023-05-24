## Лабораторна робота №12
####Тема: Взаємодія з користувачем шляхом механізму введення/виведення

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
Визначити зворотню матрицю

**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
lib.c / lib.h / main.c

 - Принцип оботи:
1)  виділення пам'яті для матриці.
2)  робимо зворотню матрицю.
5)  виведення інверсної матриці на консоль.
6)  очищення виділеної пам'яті.


- **Перелік вхідних даних:**

 - size – розмір матриці

 - **matrix – матриця

- **Дослідження результатів роботи програми**

   У функції main зчитали матрицю із файлу input.txt
   ```
   3
   1 2 0
   3 4 0
   0 0 5
   ```

•	**Перевіримо роботу функції за допомогою функції printf()**:
```
	serhii@mojavirtualka:~/tnp/programing-Stoienko/lab12$ cat ./assets/input | ./dist/main.bin 
Stoienko Serhii, KN 922-b, lab12, Vzajemodia z koristuvachem shliahom mehanizmu vvodu-vivodu
[ -2.000000 1.000000 0.000000 ]
[ 1.500000 -0.500000 0.000000 ]
[ 0.000000 0.000000 0.200000 ]

```
**Як бачимо, результати співпадають з реальними матрицями, тому функція знаходження зворотньої матриці працює**.

** Також зробимо тест **

```
serhii@mojavirtualka:~/tnp/programing-Stoienko/lab12$ dist/test.bin 
Running suite(s): Programing
determinant = 0
100%: Checks: 4, Failures: 0, Errors: 0
test/test.c:32:P:lab12:test_inverse:0: Passed
test/test.c:73:P:lab12:test_inverse_diag:0: Passed
test/test.c:96:P:lab12:test_inverse_null_det:0: Passed
test/test.c:123:P:lab12:test_inverse_one_by_one:0: Passed
...
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/programing-Stoienko/lab12/src/lib.c          51                 7    86.27%           4                 1    75.00%          67                 9    86.57%          32                 4    87.50%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                         51                 7    86.27%           4                 1    75.00%          67                 9    86.57%          32                 4    87.50%

```



**Структура проекту лабораторної роботи**:

        .
├── assets
│   └── input
├── default.profraw
├── dist
│   ├── coverage.html
│   ├── main.bin
│   ├── test.bin
│   ├── test.profdata
│   └── test.profraw
├── doc
├── doxyfile
├── Makefile
├── README.md
├── src
│   ├── lib.c
│   ├── lib.h
│   └── main.c
└── test
    └── test.c

 **Висновки**: при виконанні лабораторної роботи були набуті навички роботи з механізмами вводу та ввиводу.

 **Код проекту**:

 ** main.c : **
```
/**
  @mainpage
  Лабораторна робота №12

  @author Стоєнко Сергій Максимович:КН-922Б
  @date 22-04-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main()
{
 printf("Stoienko Serhii, KN 922-b, lab12, Vzajemodia z koristuvachem shliahom mehanizmu vvodu-vivodu\n");

 unsigned int row_col;
 scanf("%u", &row_col);

 float **matrix = get_matrix(row_col);
 for (int i = 0; i < (int)row_col; i++) {
  for (int j = 0; j < (int)row_col; j++) {
   scanf("%f", &*(*(matrix + i) + j));
  }
 }

 float **inverse = inverse_matrix(matrix, row_col);
 print_matrix(inverse, row_col);
 free_matrix(matrix, row_col);
 free_matrix(inverse, row_col);
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

void print_matrix(float **matrix, unsigned int size)
{
 for (int i = 0; i < (int)size; i++) {
  printf("[ ");
  for (int j = 0; j < (int)size; j++) {
   printf("%f ", *(*(matrix + i) + j));
  }
  printf("]\n");
 }
}

void free_matrix(float **matrix, unsigned int size)
{
 for (int i = 0; i < (int)size; i++) {
  free(*(matrix + i));
 }
 free(matrix);
}

float **get_matrix(unsigned int size)
{
 float matrix = (float )malloc(size * sizeof(float *));
 for (int i = 0; i < (int)size; i++) {
  *(matrix + i) = (float *)malloc(size * sizeof(float));
 }
 return matrix;
}

float inverse_matrix(float matrix2, unsigned int size)
{
 float **inverse = get_matrix(size);

 float **matrix = get_matrix(size);

 for (int i = 0; i < (int)size; i++) {
  for (int j = 0; j < (int)size; j++) {
   *(*(matrix + i) + j) = *(*(matrix2 + i) + j);
  }
 }

 float temp;

 for (int i = 0; i < (int)size; i++) {
  for (int j = 0; j < (int)size; j++) {
   if (i == j) {
    *(*(inverse + i) + j) = 1.0;
   } else {
    *(*(inverse + i) + j) = 0.0;
   }
  }
 }

 // perform the Gaussian elimination
 for (int k = 0; k < (int)size; k++) {
  temp = *(*(matrix + k) + k);
  for (int j = 0; j < (int)size; j++) {
   *(*(matrix + k) + j) /= temp;
   *(*(inverse + k) + j) /= temp;
   if (temp < 1e-12 && temp > -1e-12) {
    printf("determinant = 0\n");
    free_matrix(matrix, size);
    free_matrix(inverse, size);
    return NULL;
   }
  }
  for (int i = 0; i < (int)size; i++) {
   if (i != k) {
    temp = *(*(matrix + i) + k);
    for (int j = 0; j < (int)size; j++) {
     *(*(matrix + i) + j) -=
      *(*(matrix + k) + j) * temp;
     *(*(inverse + i) + j) -=
      *(*(inverse + k) + j) * temp;
    }
   }
  }
 }

 free_matrix(matrix, size);

 return inverse;
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
#include <math.h>

/**
 @brief Функція утворення зворотньої матриці.

 @param size - Розмір
 @param **matrix - масив з N * N цілих чисел
*/

float inverse_matrix(float **matrix, unsigned int size);

void print_matrix(float **matrix, unsigned int size);
void free_matrix(float **matrix, unsigned int size);
float **get_matrix(unsigned int size);
```

**test.c**
```
#include "../src/lib.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_inverse)
{
 unsigned int size = 2;

 float mas = (float )malloc(size * sizeof(float *));
 for (int i = 0; i < (int)size; i++) {
  *(mas + i) = (float *)malloc(size * sizeof(float));
 }

 *(*(mas + 0) + 0) = 1;
 *(*(mas + 0) + 1) = 2;
 *(*(mas + 1) + 0) = 3;
 *(*(mas + 1) + 1) = 4;

 float **actual = inverse_matrix(mas, size);
 float expected = (float )malloc(size * sizeof(float *));
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

 float mas = (float )malloc(size * sizeof(float *));
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
 float expected = (float )malloc(size * sizeof(float *));
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

 float mas = (float )malloc(size * sizeof(float *));
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

 float mas = (float )malloc(size * sizeof(float *));
 for (int i = 0; i < (int)size; i++) {
  *(mas + i) = (float *)malloc(size * sizeof(float));
 }
 float expected = (float )malloc(size * sizeof(float *));
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
```