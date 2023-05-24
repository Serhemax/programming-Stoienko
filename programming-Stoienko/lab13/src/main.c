/**
  @mainpage
  Лабораторна робота №13
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 14-05-2023
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include "lib.h"

int main()
{
	char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	char *string = fgets(buffer, BUFFER_SIZE, stdin);
	const size_t input_len = strlen(string);

	int *string_dig = (int *)malloc(input_len * sizeof(int));
	int *string_num = (int *)malloc(input_len * sizeof(int));

	for (int i = 0; (unsigned long)i < strlen(string); i++) {
		*(string_num + i) = -1;
		*(string_dig + i) = -1;
	}

	get_digits(string, string_dig);
	get_numbers(string, string_num);

	for (int i = 0; (unsigned long)i < strlen(string); i++) {
		if (*(string_num + i) > -1) {
			printf("%d ", *(string_num + i));
		}
	}

	printf("\n");

	for (int i = 0; (unsigned long)i < strlen(string); i++) {
		if (*(string_dig + i) > -1) {
			printf("%d ", *(string_dig + i));
		}
	}

	free(buffer);
	free(string_num);
	free(string_dig);

	return 0;
}
