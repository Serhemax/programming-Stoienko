

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
#include <math.h>

/** 
	@brief Функція eлементи головної діагоналі масивa N*N записує в одновимірний масив, отриманий масив упорядкoвує за зростанням.
	
	@param N - Розмір
	@param **mas - масив з N * N цілих чисел
	@param *diagmas - Масив, який будемо заповнювати)
*/

float **inverse_matrix(float **matrix, unsigned int size);

void print_matrix(float **matrix, unsigned int size);
void free_matrix(float **matrix, unsigned int size);
float **get_matrix(unsigned int size);
