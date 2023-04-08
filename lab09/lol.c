void multiply_matrix(int argc, char *argv[], int *multiply)
{
	long int mas[15][15];

	long int array_size;
	
	long int symbol_number = 2;
	char *nul;

	if (argc > 1)
	{
		array_size = strtol(argv[1], &nul, argc);

	} else {
		array_size = 3;
	}

	for (int row = 0; row < array_size; row++)

	{
		for (int coll = 0; coll < array_size; coll++) {
			mas[row][coll] =
				strtol(argv[symbol_number], &nul, argc);

			symbol_number++;
		}
	}


	for (int row = 0; row < array_size; row++) {

		for (int coll = 0; coll < array_size; coll++) {

			multiply[array_size * row + coll] = 0;

			for (int times = 0; times < array_size; times++) {

				multiply[array_size * row + coll] +=
					mas[row][times] * mas[times][coll];
			}
		}
	}
	for (int row = 0; row < array_size; row++) {
		int new_line = 0;
		for (int coll = 0; coll < array_size; coll++) {
			printf("%d\t", multiply[array_size * row + coll]);
			new_line++;
			if (new_line == array_size) {
				new_line = 0;
				printf("\n");
			}
		}
	}
}



