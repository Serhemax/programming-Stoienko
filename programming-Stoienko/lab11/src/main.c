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
