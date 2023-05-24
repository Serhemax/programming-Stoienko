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

int main(int argc, char **argv)
{
	// Ensure that the input file was specified
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Open the input file
	FILE *input_fp = fopen(argv[1], "r");
	if (input_fp == NULL) {
		fprintf(stderr, "Error: Could not open input file '%s'\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}

	// Read the parameters from the input file
	int amplitude, period;
	char symbol;
	fscanf(input_fp, "%d %d %c", &amplitude, &period, &symbol);

	fclose(input_fp);

	// Open the output file
	FILE *output_fp = fopen("output.txt", "w");
	if (output_fp == NULL) {
		fprintf(stderr,
			"Error: Could not open output file 'output.txt'\n");
		exit(EXIT_FAILURE);
	}

	create_wave(amplitude, period, symbol, output_fp);

	fclose(output_fp);

	return 0;
}
