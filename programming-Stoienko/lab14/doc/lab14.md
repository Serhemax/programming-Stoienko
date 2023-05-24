## Лабораторна робота №14
####Тема: Взаємодія з файлами
Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
Розробити програму, що в заданому файлі створює горизонтальну синусоїду із заданих символів (наприклад, зірочок). Амплітуда синусоїди, символ заповнювача та період задається у вхідному файлу.

**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
lib.c / lib.h / main.c

 - Принцип оботи:
1)  відкриваємо файл.
2)  зчитуємо з нього амплітуду та період коливання та символ, яким будемо малювати.
3)  за допомгою фізичних рівнянь рахуємо як малювати синусоїд та креслимо його в вихідний файл.


- **Перелік вхідних даних:**

 - amplitude – амплітуда синусоїди

 - period – період синусоїди

 - symbol - символ креслення

 - fp - файл виводу

- **Дослідження результатів роботи програми**

   У функції main зчитали дані із файлу input.txt
   ```
   5 45 *
   ```

•	**Перевіримо роботу функції у файлі output.txt**:
```
	serhii@mojavirtualka:~/tnp/programing-Stoienko/lab14$ ./dist/main.bin ./assets/input ./dist/output.txt
```
**Як бачимо, результати співпадають з реальними матрицями, тому функція знаходження зворотньої матриці працює**.

** Також зробимо тест **

```
serhii@mojavirtualka:~/tnp/programing-Stoienko/lab14$ dist/test.bin 
Running suite(s): Programing
100%: Checks: 1, Failures: 0, Errors: 0
test/test.c:5:P:lab14:test_create_sine_wave:0: Passed
...
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/serhii/tnp/programing-Stoienko/lab14/src/lib.c          12                 0   100.00%           1                 0   100.00%          16                 0   100.00%           8                 0   100.00%
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                         12                 0   100.00%           1                 0   100.00%          16                 0   100.00%           8
```



**Структура проекту лабораторної роботи**:

├── assets
│   └── input
├── default.profraw
├── doc
├── doxyfile
├── Makefile
├── README.md
├── src
│   ├── lib.c
│   ├── lib.h
│   └── main.c
├── test
│   └── test.c
└── test.txt

 **Висновки**: при виконанні лабораторної роботи були набуті навички роботи з файлами.

 **Код проекту**:

 ** main.c : **
```
/**
  @mainpage
  Лабораторна робота №14
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 14-05-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main(int argc, char **argv)
{
 // Ensure that the input file was specified
 if (argc < 2) {
  fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
  exit(EXIT_FAILURE);
 }

 // Open the input file
 FILE *input_fp = fopen(argv[1], "r");
 if (input_fp == NULL) {
  fprintf(stderr, "Error: Could not open input file '%s'\n",
   argv[1]);
  exit(EXIT_FAILURE);
 }

 // Read the parameters from the input file
 int amplitude, period;
 char symbol;
 fscanf(input_fp, "%d %d %c", &amplitude, &period, &symbol);

 fclose(input_fp);

 // Open the output file
 FILE *output_fp = fopen("output.txt", "w");
 if (output_fp == NULL) {
  fprintf(stderr,
   "Error: Could not open output file 'output.txt'\n");
  exit(EXIT_FAILURE);
 }

 create_wave(amplitude, period, symbol, output_fp);

 fclose(output_fp);

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

void create_wave(int amplitude, int period, char symbol, FILE *fp)
{
 // Calculate the horizontal displacement of each character
 double delta_x = 2.0 * M_PI / (double)period;

 // Iterate through each row of the wave
 for (int y = amplitude; y >= -amplitude; y--) {
  // Iterate through each column of the wave
  for (int x = 0; x < period; x++) {
   // Calculate the horizontal displacement of this character
   double alpha = delta_x * (double)x;
   double displacement = amplitude * sin(alpha);

   // Determine whether to output the fill character or a space
   if (displacement >= (double)y - 0.5 &&
       displacement <= (double)y + 0.5) {
    fputc(symbol, fp);
   } else {
    fputc(' ', fp);
   }
  }

  // End the row with a newline character
  fputc('\n', fp);
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
#include <math.h>

void create_wave(int amplitude, int period, char fill_char, FILE *fp);
```

**test.c**
```
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
```