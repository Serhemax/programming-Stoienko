
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
#include <string.h>

/// Базовий клас - Птах
typedef struct {
	int is_ringed; // Чи окольцьована птаха (так, ні)
	char *type; // Назва виду
	int age; // Вік птаха, місяців
	struct {
		int area; // Площа у кв. см
		int height; // Висота у см
		int feeders; // Кількість годівниць
		int has_nest; // Наявність гнізда (так, ні)
	} home; // Тип домівки птаха
	char *gender; // Стать птаха (чоловіча, жіноча)
} Bird;

Bird *read_bird(const char *filename, int *num_birds);
/// Функція для запису масиву птахів до файлу
void write_birds_to_file(const char *filename, const Bird *birds,
			 int num_birds);
/// Функція для виведення масиву птахів на екран
void print_birds(const Bird *birds, int num_birds);
/// Функція для знаходження відсоткового відношення самок до самців у відділі
float get_gender_ratio(const Bird *birds, int num_birds);
