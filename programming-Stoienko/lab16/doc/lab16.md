## Лабораторна робота №16
####Тема: Динамічні масиви

Виконав:
Стоєнко Сергій Максимович
Група виконавця: КН-922Б

**Завдання:**
```
23. Птахи

У відділі орнітології почався перепис усіх зареєстрованих птахів. Вчені збирають наступну інформацію щодо птахів:

    Поля базового класу:
        Чи окольцьована птаха (наприклад: так, ні)
        Назва виду (наприклад: журавель, гусак)
        Вік птаха, місяців (наприклад: 2, 6, 8)
        Тип домівки птаха (структура, що містить площу у кв.см, висоту у см домівки птаха, а також кількість годівниць та наявність гнізда)
        Стать птаха (один з переліку: чоловіча, жіноча)
    Спадкоємець 1 - Перелітні птахи. Додаткові поля:
        Місяць відльоту у вирій (один з переліку: січень, лютий, березень, … , грудень)
        Місяць прильоту з вирію (один з переліку: січень, лютий, березень, … , грудень)
    Спадкоємець 2 - Екзотичні птахи. Додаткові поля:
        Мінімальна комфортна для життя температура, градусів Цельсію (наприклад: -5, +10, +15)
        Максимальна комфортна для життя температура, градусів Цельсію (наприклад: +5, +20, +40)
    Методи для роботи з колекцією:
        Знайти відсоткове відношення самок до самців у відділі
```
**Основна частина:**

- **Опис роботи основної функції: **

 - Основні функції
lib.c / lib.h / main.c

 - Принцип роботи:
1)  відкриваємо файл.
2)  зчитуємо з нього інформацію про птаха/ів
3)  реалізуємо функцію додавання птаха: створюємо масив розміром на 1 більше ніж наш попередній і копіюємо старий в новий масив та додаємо нову птицю
4) реалізовуєємо функцію видалення птаха: звільняємо пам'ять для птаха за заданним індексом, потім ідемо від цбого індекса до кінця масива та присвоюємо значення наступних елементів, до теперішнього
5) реалізуємо функцію сортування: створюємо функцію порівняння 2 птахів за віком та використовуємо функцію qsort()
6) після виконання кожної функції, виписуємо її на екран


- **Перелік вхідних даних:**

 - argc – розмір строки

 - argv – назви файлів вводу та ввиводу, які вводе користувач
 - new_bird - нова птицю, яку будемо додавати
 - idx - індекс видалення

- **Дослідження результатів роботи програми**

   У функції read_bird зчитали дані із файлу input.txt
   ```
3
1,журавель,2,100,50,2,1,чоловіча
0,гусак,6,200,75,1,0,жіноча
1,сорока,8,150,60,3,1,чоловіча
   ```

•	**Перевіримо чи зчиталась інформація за допомогою функції print_birds() та чи працює функція знаходження відсотка жіночої статті за допомогою функції printf():**
```
	serhii@mojavirtualka:~/tnp/tnpp/programming-Stoienko/lab16$ dist/main.bin ./assets/input ./dist/output.txt
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: сорока
  Вік: 8 місяців
  Домівка:
    Площа: 150 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After add_bird
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: сорока
  Вік: 8 місяців
  Домівка:
    Площа: 150 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

Птах 4:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After remove_bird
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After sort
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

Птах 3:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча
```
**Як бачимо, результати співпадають з реальними матрицями, тому функції працюють**.

** Також зробимо тест **

```
serhii@mojavirtualka:~/tnp/tnpp/programming-Stoienko/lab16$ dist/main.bin ./assets/input ./dist/output.txt
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: сорока
  Вік: 8 місяців
  Домівка:
    Площа: 150 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After add_bird
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: сорока
  Вік: 8 місяців
  Домівка:
    Площа: 150 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

Птах 4:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After remove_bird
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча

Птах 3:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

/////////////////
After sort
/////////////////
Птах 1:
  Чи окольцьований: 1
  Назва виду: журавель
  Вік: 2 місяців
  Домівка:
    Площа: 100 кв. см
    Висота: 50 см
    Кількість годівниць: 2
    Наявність гнізда: 1
  Стать: чоловіча

Птах 2:
  Чи окольцьований: 1
  Назва виду: горобець
  Вік: 3 місяців
  Домівка:
    Площа: 90 кв. см
    Висота: 60 см
    Кількість годівниць: 3
    Наявність гнізда: 1
  Стать: чоловіча

Птах 3:
  Чи окольцьований: 0
  Назва виду: гусак
  Вік: 6 місяців
  Домівка:
    Площа: 200 кв. см
    Висота: 75 см
    Кількість годівниць: 1
    Наявність гнізда: 0
  Стать: жіноча
```



**Структура проекту лабораторної роботи**:

.
├── assets
│   └── input
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
│   ├── entity.c
│   ├── entity.h
│   ├── list.c
│   ├── list.h
│   └── main.c
├── test
│   └── test.c
└── test_input.txt
 **Висновки**: при виконанні лабораторної роботи були набуті навички роботи із динамічними масивами.

 **Код проекту**:

 ** main.c : **
```
/**
  @mainpage
  Лабораторна робота №16

  @author Стоєнко Сергій Максимович:КН-922Б
  @date 14-05-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "list.h"

int main(int argc, char *argv[]) {
  int num_birds;
  Bird *birds;
  int i;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input output\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  birds = read_bird(argv[1], &num_birds);

  Bird new_bird = {1, "горобець", 3, {90, 60, 3, 1}, "чоловіча"};

  print_birds(birds, num_birds);

  // Додавання птахів до списку птахів
  add_bird(&birds, &num_birds, new_bird);

  printf("/////////////////\nAfter add_bird\n/////////////////\n");

  print_birds(birds, num_birds);

  remove_bird_in(&birds, &num_birds, 2);

  printf("/////////////////\nAfter remove_bird\n/////////////////\n");

  print_birds(birds, num_birds);

  qsort(birds, (size_t)num_birds, (size_t)sizeof(Bird), compare_birds_age);

  printf("/////////////////\nAfter sort\n/////////////////\n");

  print_birds(birds, num_birds);

  // Звільняємо пам'ять, яку було виділено для зберігання даних про птахів
  for (i = 0; i < num_birds; i++) {
    free((birds + i)->type);
    free((birds + i)->gender);
  }

  free(birds);

  return 0;
}
```

** list.c **

```
#include "list.h"

void write_birds_to_file(const char *filename, const Bird *birds,
                         int num_birds) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Помилка відкриття файлу.\n");
    return;
  }

  for (int i = 0; i < num_birds; i++) {
    fprintf(file, "%d %s %d %d %d %d %d %s\n", birds[i].is_ringed,
            birds[i].type, birds[i].age, birds[i].home.area,
            birds[i].home.height, birds[i].home.feeders, birds[i].home.has_nest,
            birds[i].gender);
  }

  fclose(file);
}

float get_gender_ratio(const Bird *birds, int num_birds) {
  int males = 0;
  int females = 0;

  for (int i = 0; i < num_birds; i++) {
    if (strcmp(birds[i].gender, "чоловіча") == 0) {
      males++;
    } else if (strcmp(birds[i].gender, "жіноча") == 0) {
      females++;
    }
  }
  if (males + females > 0) {
    return (float)females / (float)(males + females) * 100.0f;
  } else {
    return 0.0;
  }
}

void add_bird(Bird **birds, int *num_birds, Bird new_bird) {
  Bird *new_list_birds = malloc((size_t)(*num_birds + 1) * sizeof(Bird));
  // Копіювання вмісту старого масиву до нового
  memcpy(new_list_birds, *birds, ((size_t)*num_birds * sizeof(Bird)));
  // Додавання нового елемента
  new_list_birds[*num_birds] = new_bird;
  // Збільшення лічильника
  (*num_birds)++;
  // Звільнення пам'яті, виділеної для старого масиву
  free(*birds);
  // Присвоєння нової адреси масиву
  *birds = new_list_birds;
}

void remove_bird_in(Bird **birds, int *num_birds, int idx) {
  if (idx < 0 || idx >= *num_birds) {
    fprintf(stderr, "Error: Index out of range\n");
    exit(EXIT_FAILURE);
  }

  free(((*birds)[idx].type));
  free(((*birds)[idx].gender));

  for (int i = idx; i < *num_birds - 1; i++) {
    (*birds)[i] = (*birds)[i + 1];
  }

  *num_birds -= 1;
}

int compare_birds_age(const void *age1, const void *age2) {
  const Bird *bird_age1 = (const Bird *)age1;
  const Bird *bird_age2 = (const Bird *)age2;
  return bird_age1->age - bird_age2->age;
}
```

**list.h**

```
#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_birds_to_file(const char *filename, const Bird *birds,
                         int num_birds);
// Функція для знаходження відсоткового відношення самок до самців у відділі
float get_gender_ratio(const Bird *birds, int num_birds);
void add_bird(Bird **birds, int *num_birds, Bird new_bird);
void remove_bird_in(Bird **birds, int *num_birds, int idx);
void sort(Bird **birds, int *num_birds);
int compare_birds_age(const void *age1, const void *age2);
```
**entity.c**
```

#include "entity.h"

Bird *read_bird(const char *filename, int *num_birds) {
  FILE *fp;
  char line[256];
  Bird *birds;
  int i = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // Першим рядком в файлі має бути кількість птахів
  fgets(line, sizeof(line), fp);
  *num_birds = atoi(line);
  birds = malloc((size_t)*num_birds * sizeof(Bird));

  while (fgets(line, sizeof(line), fp)) {
    int is_ringed = atoi(strtok(line, ","));
    char *type = strtok(NULL, ",");
    int age = atoi(strtok(NULL, ","));
    int area = atoi(strtok(NULL, ","));
    int height = atoi(strtok(NULL, ","));
    int feeders = atoi(strtok(NULL, ","));
    int has_nest = atoi(strtok(NULL, ","));
    char *gender = strtok(NULL, " \n");

    birds[i].is_ringed = is_ringed;
    birds[i].type = strdup(type);
    birds[i].age = age;
    birds[i].home.area = area;
    birds[i].home.height = height;
    birds[i].home.feeders = feeders;
    birds[i].home.has_nest = has_nest;
    birds[i].gender = strdup(gender);
    i++;
  }

  fclose(fp);

  return birds;
}

// Функція для виведення масиву птахів на екран
void print_birds(const Bird *birds, int num_birds) {
  for (int i = 0; i < num_birds; i++) {
    printf("Птах %d:\n", i + 1);
    printf("  Чи окольцьований: %d\n", birds[i].is_ringed);
    printf("  Назва виду: %s\n", birds[i].type);
    printf("  Вік: %d місяців\n", birds[i].age);
    printf("  Домівка:\n");
    printf("    Площа: %d кв. см\n", birds[i].home.area);
    printf("    Висота: %d см\n", birds[i].home.height);
    printf("    Кількість годівниць: %d\n", birds[i].home.feeders);
    printf("    Наявність гнізда: %d\n", birds[i].home.has_nest);
    printf("  Стать: %s\n", birds[i].gender);
    printf("\n");
  }
}
```
**entity.h**
```
#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Базовий клас - Птах
typedef struct {
  int is_ringed; // Чи окольцьована птаха (так, ні)
  char *type;    // Назва виду
  int age;       // Вік птаха, місяців
  struct {
    int area;     // Площа у кв. см
    int height;   // Висота у см
    int feeders;  // Кількість годівниць
    int has_nest; // Наявність гнізда (так, ні)
  } home;         // Тип домівки птаха
  char *gender;   // Стать птаха (чоловіча, жіноча)
} Bird;

Bird *read_bird(const char *filename, int *num_birds);
/// Функція для виведення масиву птахів на екран
void print_birds(const Bird *birds, int num_birds);
#endif
```

**test.c**
```
#include "entity.h"
#include "list.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_read_birds) {
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
START_TEST(test_num_birds) {
  int num_birds;
  Bird *birds = read_bird("test_input.txt", &num_birds);

  ck_assert_int_eq(num_birds, 3);

  for (int i = 0; i < 3; i++) {
    free(birds[i].type);
    free(birds[i].gender);
  }
}
END_TEST
START_TEST(test_get_gender_ratio) {
  int num_birds;
  Bird *birds = read_bird("test_input.txt", &num_birds);

  ck_assert_float_eq_tol(get_gender_ratio(birds, num_birds),
                         1.0f / 3.0f * 100.0f, 0.01);

  for (int i = 0; i < 3; i++) {
    free(birds[i].type);
    free(birds[i].gender);
  }
}
END_TEST
START_TEST(test_add_bird) {
  int num_birds;
  Bird *birds = read_bird("test_input.txt", &num_birds);

  Bird new_bird = {0, "горобець", 5, {90, 65, 2, 0}, "чоловіча"};

  add_bird(&birds, &num_birds, new_bird);

  ck_assert_int_eq(birds[3].is_ringed, 0);
  ck_assert_str_eq(birds[3].type, "горобець");
  ck_assert_int_eq(birds[3].age, 5);
  ck_assert_int_eq(birds[3].home.area, 90);
  ck_assert_int_eq(birds[3].home.height, 65);
  ck_assert_int_eq(birds[3].home.feeders, 2);
  ck_assert_int_eq(birds[3].home.has_nest, 0);
  ck_assert_str_eq(birds[3].gender, "чоловіча");

  for (int i = 0; i < 3; i++) {
    free(birds[i].type);
    free(birds[i].gender);
  }
}
END_TEST
START_TEST(test_remove_bird_in) {
  int num_birds;
  Bird *birds = read_bird("test_input.txt", &num_birds);

  remove_bird_in(&birds, &num_birds, 1);

  ck_assert_int_eq(birds[1].is_ringed, 1);
  ck_assert_str_eq(birds[1].type, "сорока");
  ck_assert_int_eq(birds[1].age, 8);
  ck_assert_int_eq(birds[1].home.area, 150);
  ck_assert_int_eq(birds[1].home.height, 60);
  ck_assert_int_eq(birds[1].home.feeders, 3);
  ck_assert_int_eq(birds[1].home.has_nest, 1);
  ck_assert_str_eq(birds[1].gender, "жіноча");

  for (int i = 0; i < 2; i++) {
    free(birds[i].type);
    free(birds[i].gender);
  }
}
END_TEST
START_TEST(test_sort) {
  int num_birds;
  Bird *birds = read_bird("test_input.txt", &num_birds);

  qsort(birds, (size_t)num_birds, (size_t)sizeof(Bird), compare_birds_age);

  ck_assert_int_eq(birds[0].age, 2);
  ck_assert_int_eq(birds[1].age, 6);
  ck_assert_int_eq(birds[2].age, 8);

  for (int i = 0; i < 2; i++) {
    free(birds[i].type);
    free(birds[i].gender);
  }
}
END_TEST

int main(void) {
  Suite *s = suite_create("Programing");
  TCase *tc_core = tcase_create("lab15");

  tcase_add_test(tc_core, test_read_birds);
  tcase_add_test(tc_core, test_num_birds);
  tcase_add_test(tc_core, test_get_gender_ratio);
  tcase_add_test(tc_core, test_add_bird);
  tcase_add_test(tc_core, test_remove_bird_in);
  tcase_add_test(tc_core, test_sort);

  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
```