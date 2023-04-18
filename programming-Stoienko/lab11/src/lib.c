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
