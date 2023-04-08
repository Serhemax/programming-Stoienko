/**
  @mainpage
  Лабораторна робота №9
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 12-03-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main()
{
	int first_number = 100;
	int second_number = 50;
	//int multiply[15][15];

	//multiply_matrix(argc, argv, (int *)multiply);

	int nsd = find_nsd(first_number, second_number);

	printf(" first number = %d\n second number = %d\n nsd = %d\n",
	       first_number, second_number, nsd);

	return 0;
}
