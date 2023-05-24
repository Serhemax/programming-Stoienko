## Лабораторна робота №13
####Тема: Строки (Null-terminated C Strings)

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
Знайти всі цифри, які зустрічаються в тексті.

**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
lib.c / lib.h / main.c

 - Принцип роботи:
(Я не зрозумів чи потрібно було шукати числа, чи цифри, тому зробив 2 функції)

	1)  виділення пам'яті для строки та массиву для знаходження цифр та чисел.
	2)  робиться присвоєння строки та заповнюємо масиви цифр та чисел -1
	3)  проходимось по цій строці і якщо там є цифра, то записуємо її в масив цифр, якщо після цієї цифри є наступна цифра, то ми йдемо по строчці доки число не скінчиться і потім його записуємо
	4)  виведення масиву чисел та цифр на консоль.
	5)  очищення виділеної пам'яті.


- **Перелік вхідних даних:**

 - *string – строка

- **Дослідження результатів роботи програми**

   У функції main зчитали строку із файлу input.txt
   ```
   So there was 5 different thing and 12 other things. Also 34 different songs and 25 types of vine
   ```

•	**Перевіримо роботу функції за допомогою функції printf()**:
```
	serhii@mojavirtualka:~/tnp/programing-Stoienko/lab13$ cat ./assets/input | ./dist/main.bin
5 12 34 25
5 1 2 3 4 2 5

```
**Як бачимо, результати співпадають з реальними масивами, тому функція знаходження відсортованної матриці працює**.

** Також зробимо тест **

```
serhii@mojavirtualka:~/tnp/programing-Stoienko/lab13$ dist/test.bin 
Running suite(s): Programing
100%: Checks: 4, Failures: 0, Errors: 0
test/test.c:22:P:lab13:test_dig:0: Passed
test/test.c:29:P:lab13:test_dig_null:0: Passed
test/test.c:85:P:lab13:test_num:0: Passed
test/test.c:113:P:lab13:test_num_null:0: Passed

serhii@mojavirtualka:~/tnp/programing-Stoienko/lab11$ make test
...
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/programing-Stoienko/lab13/src/lib.c          14                 0   100.00%           2                 0   100.00%          28                 0   100.00%           6                 1    83.33%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                         14                 0   100.00%           2                 0   100.00%          28                 0   100.00%           6                 1    83.33%
```



**Структура проекту лабораторної роботи**:

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

 **Висновки**: при виконанні лабораторної роботи були набуті навички роботи зі String.


**Код проекту**:


** main.c : **
```
/**
  @mainpage
  Лабораторна робота №13
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 14-05-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main()
{
 char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
 char *string = fgets(buffer, BUFFER_SIZE, stdin);
 const size_t input_len = strlen(string);

 int *string_dig = (int *)malloc(input_len * sizeof(int));
 int *string_num = (int *)malloc(input_len * sizeof(int));

 for (int i = 0; (unsigned long)i < strlen(string); i++) {
  *(string_num + i) = -1;
  *(string_dig + i) = -1;
 }

 get_digits(string, string_dig);
 get_numbers(string, string_num);

 for (int i = 0; (unsigned long)i < strlen(string); i++) {
  if (*(string_num + i) > -1) {
   printf("%d ", *(string_num + i));
  }
 }

 printf("\n");

 for (int i = 0; (unsigned long)i < strlen(string); i++) {
  if (*(string_dig + i) > -1) {
   printf("%d ", *(string_dig + i));
  }
 }

 free(buffer);
 free(string_num);
 free(string_dig);

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

void get_digits(const char *string, int *string_dig)
{
 int idx = 0;
 for (int i = 0; (unsigned long)i < strlen(string); i++) {
  if (isdigit(*(string + i))) {
   *(string_dig + idx) = (*(string + i) - '0');
   idx++;
  }
 }
}
void get_numbers(const char *string, int *string_num)
{
 int in_number = 0;
 int jjj = 0;
 int num = 0;
 int idx = 0;

 for (int i = 0; (unsigned long)i < strlen(string); i++) {
  if (isdigit(*(string + i))) {
   num = *(string + i) - '0';
   for (jjj = i + 1; (unsigned long)jjj < strlen(string) &&
       isdigit(*(string + jjj));
        jjj++) {
    num = num * 10 + (*(string + jjj) - '0');
   }
   *(string_num + idx) = num;
   idx++;
   i = jjj;
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
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

void get_digits(const char *string, int *string_dig);
void get_numbers(const char *string, int *string_num);
```

**test.c**

```
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
```

