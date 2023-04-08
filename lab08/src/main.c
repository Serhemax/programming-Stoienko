/**
  \mainpage
  Лабораторна робота №8
 
  @author Стоєнко Сергій Максимович:КН-922Б
  @date 27-11-2022
*/

/**
@file main.c
@brief Головний файл

Це файл, в який містить точку входу, функції та їх аргументи
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_nsd(int first_number, int second_number);
void multiply_matrix(int argc, char *argv[], int *multiply);

/**
	Тут ми створюємо 2 випадкових числа від 1 до 100 для функції
	знаходження НСД та порожню матрицю multiply, яка буде містити 
	до 15 елементів, та в яку ми будемо записувати нову помножену
	матрицю для функції множення матриць.
	@param argc[in] - Записана з командного рядка кількість рядків(стовпців) в матриці
	@param argv[in] - Записана з командного рядка матриця, яку ми хочемо помножити
*/
int main(int argc, char *argv[])
{
	srand((unsigned int)time(0));

	int first_number = random() % 100;
	int second_number = random() % 100;
	int multiply[15][15];

	multiply_matrix(argc, argv, (int *)multiply);

	int nsd = find_nsd(first_number, second_number);

	/// show on screen
	printf(" first number = %d\n second number = %d\n nsd = %d\n",
	       first_number, second_number, nsd);

	return 0;
}

/** 
	@brief Функція знаходження НСД двох випадкових чисел
	
	@param first_number[in] - Перше випадкове число
	@param second_number[in] - Друге випадкове число
	@return НСД
*/
int find_nsd(int first_number, int second_number)
{
	// create first and second number

	int larger_number;
	int nsd = 1;

	//we need to check which of the numbers are larger
	//and assign new valuble to variable larger_number
	//for knowing, what number is larger for cycle for
	if (second_number >= first_number) {
		larger_number = second_number;
	} else {
		larger_number = first_number;
	}

	for (int i = 1; i <= larger_number; i++) {
		// if numbers are both evenly divisible by i, then i
		// is common factor, the last i, that gonna be common
		// facor of the numbers, is largest
		if (first_number % i == 0 && second_number % i == 0) {
			nsd = i;
		}
	}

	return nsd;
}

/** 
	@brief Функція множення матриць
	 
	@param argc[in] - Кількість рядків(стовпців) в матриці
	@param argv[in] - Матриця, яку ми хочемо помножити
	@param multiply - порожня матриця
*/
void multiply_matrix(int argc, char *argv[], int *multiply)
{
	long int mas[15][15];

	long int array_size;
	//
	long int symbol_number = 2;
	char *nul;

	if (argc > 1)
	// Перевіряємо чи були введені данні у командний рядок.
	{
		// Знаходимо розмір матриці, він записан першим в масиві символів
		array_size = strtol(argv[1], &nul, argc);

	} else {
		// Якщо ні, то тоді буде нульова матриця розмірами 3 на 3
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

	// Так як треба множити матрицю на саму себе, то це повинна бути
	// квадратична матриця, бо інакше число рядків та стовпців не будуть
	// співпадати, а тоді не можна множити(за правилами множення).

	// рядок
	for (int row = 0; row < array_size; row++) {
		// стовпчик
		for (int coll = 0; coll < array_size; coll++) {
			// даємо значення елементу матриці
			multiply[array_size * row + coll] = 0;
			// скільки разів множемо рядок матриці на стовпчик
			for (int times = 0; times < array_size; times++) {
				// Помножимо рядок матриці на стовпчик матриці та отримуємо
				// елемент на рядку та стовпчику матриці добутка
				multiply[array_size * row + coll] +=
					mas[row][times] * mas[times][coll];
			}
		}
	}
	for (int row = 0; row < array_size; row++) {
		int new_line = 0;
		// стовпчик
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
