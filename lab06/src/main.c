#include <stdio.h>
#include <stdlib.h>

int main()
{
//кількість рядків та стовпчиків у матриці
#define Amount 3
	// Створюємо матрицю, та оголошуємо матрицю добутка матриць
	// Так як треба множити матрицю на саму себе, то це повинна бути
	// квадратична матриця, бо інакше число рядків та стовпців не будуть
	// співпадати, а тоді не можна множити(за правилами множення).
	int mas[Amount][Amount] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int multiply[Amount][Amount];

	// рядок
	for (int row = 0; row < Amount; row++) {
		// стовпчик
		for (int coll = 0; coll < Amount; coll++) {
			// даємо значення елементу матриці
			multiply[row][coll] = 0;
			// скільки разів множемо рядок матриці на стовпчик
			for (int times = 0; times < Amount; times++) {
				// Помножимо рядок матриці на стовпчик матриці та отримуємо
				// елемент на рядку та стовпчику матриці добутка
				multiply[row][coll] +=
					mas[row][times] * mas[times][coll];
			}
		}
	}
	return 0;
}
