/**
 * @file lib.c
 * @brief 
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include "lib.h"

void print_matrix(float **matrix, unsigned int size)
{
	for (int i = 0; i < (int)size; i++) {
		printf("[ ");
		for (int j = 0; j < (int)size; j++) {
			printf("%f ", *(*(matrix + i) + j));
		}
		printf("]\n");
	}
}

void free_matrix(float **matrix, unsigned int size)
{
	for (int i = 0; i < (int)size; i++) {
		free(*(matrix + i));
	}
	free(matrix);
}

float **get_matrix(unsigned int size)
{
	float **matrix = (float **)malloc(size * sizeof(float *));
	for (int i = 0; i < (int)size; i++) {
		*(matrix + i) = (float *)malloc(size * sizeof(float));
	}
	return matrix;
}

float **inverse_matrix(float **matrix2, unsigned int size)
{
	float **inverse = get_matrix(size);

	float **matrix = get_matrix(size);

	for (int i = 0; i < (int)size; i++) {
		for (int j = 0; j < (int)size; j++) {
			*(*(matrix + i) + j) = *(*(matrix2 + i) + j);
		}
	}

	float temp;

	for (int i = 0; i < (int)size; i++) {
		for (int j = 0; j < (int)size; j++) {
			if (i == j) {
				*(*(inverse + i) + j) = 1.0;
			} else {
				*(*(inverse + i) + j) = 0.0;
			}
		}
	}

	// perform the Gaussian elimination
	for (int k = 0; k < (int)size; k++) {
		temp = *(*(matrix + k) + k);
		for (int j = 0; j < (int)size; j++) {
			*(*(matrix + k) + j) /= temp;
			*(*(inverse + k) + j) /= temp;
			if (temp < 1e-12 && temp > -1e-12) {
				printf("determinant = 0\n");
				free_matrix(matrix, size);
				free_matrix(inverse, size);
				return NULL;
			}
		}
		for (int i = 0; i < (int)size; i++) {
			if (i != k) {
				temp = *(*(matrix + i) + k);
				for (int j = 0; j < (int)size; j++) {
					*(*(matrix + i) + j) -=
						*(*(matrix + k) + j) * temp;
					*(*(inverse + i) + j) -=
						*(*(inverse + k) + j) * temp;
				}
			}
		}
	}

	free_matrix(matrix, size);

	return inverse;
}
