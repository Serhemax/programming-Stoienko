

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

        @param N - Розмір
        @param **mas - масив з N * N цілих чисел
        @param *diagmas - Масив, який будемо заповнювати)
*/

void diagonalElements(unsigned int size, int **mas, int *diagmas);

/**
        @brief Функція cортування BubbleSort

        @param n - Розмір
        @param *arr - масив
*/
void bubbleSort(int *arr, unsigned int size);
