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

int main(int argc, char *argv[]) {
  int num_birds;
  Bird *birds;
  int i;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s input output\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  birds = read_bird(argv[1], &num_birds);

  write_birds_to_file(argv[2], birds, num_birds);
  print_birds(birds, num_birds);

  float gender_ratio = get_gender_ratio(birds, num_birds);

  printf("відсотковe відношення самок до самців у відділі: %.2f%%\n",
         gender_ratio);

  // Звільняємо пам'ять, яку було виділено для зберігання даних про птахів
  for (i = 0; i < num_birds; i++) {
    free((birds + i)->type);
    free((birds + i)->gender);
  }

  free(birds);

  return 0;
}
