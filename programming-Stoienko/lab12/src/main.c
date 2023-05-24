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
