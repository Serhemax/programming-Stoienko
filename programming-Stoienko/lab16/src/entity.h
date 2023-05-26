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
