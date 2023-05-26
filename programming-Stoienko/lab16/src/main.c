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
