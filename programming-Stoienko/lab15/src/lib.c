/**
 * @file lib.c
 * @brief 
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include "lib.h"

Bird *read_bird(const char *filename, int *num_birds)
{
	FILE *fp;
	char line[256];
	Bird *birds;
	int i = 0;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	// Першим рядком в файлі має бути кількість птахів
	fgets(line, sizeof(line), fp);
	*num_birds = atoi(line);
	birds = malloc((size_t)*num_birds * sizeof(Bird));

	while (fgets(line, sizeof(line), fp)) {
		int is_ringed = atoi(strtok(line, ","));
		char *type = strtok(NULL, ",");
		int age = atoi(strtok(NULL, ","));
		int area = atoi(strtok(NULL, ","));
		int height = atoi(strtok(NULL, ","));
		int feeders = atoi(strtok(NULL, ","));
		int has_nest = atoi(strtok(NULL, ","));
		char *gender = strtok(NULL, " \n");

		birds[i].is_ringed = is_ringed;
		birds[i].type = strdup(type);
		birds[i].age = age;
		birds[i].home.area = area;
		birds[i].home.height = height;
		birds[i].home.feeders = feeders;
		birds[i].home.has_nest = has_nest;
		birds[i].gender = strdup(gender);
		i++;
	}

	fclose(fp);

	return birds;
}

// Функція для запису масиву птахів до файлу
void write_birds_to_file(const char *filename, const Bird *birds, int num_birds)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Помилка відкриття файлу.\n");
		return;
	}

	for (int i = 0; i < num_birds; i++) {
		fprintf(file, "%d %s %d %d %d %d %d %s\n", birds[i].is_ringed,
			birds[i].type, birds[i].age, birds[i].home.area,
			birds[i].home.height, birds[i].home.feeders,
			birds[i].home.has_nest, birds[i].gender);
	}

	fclose(file);
}

// Функція для виведення масиву птахів на екран
void print_birds(const Bird *birds, int num_birds)
{
	for (int i = 0; i < num_birds; i++) {
		printf("Птах %d:\n", i + 1);
		printf("  Чи окольцьований: %c\n", birds[i].is_ringed);
		printf("  Назва виду: %s\n", birds[i].type);
		printf("  Вік: %d місяців\n", birds[i].age);
		printf("  Домівка:\n");
		printf("    Площа: %d кв. см\n", birds[i].home.area);
		printf("    Висота: %d см\n", birds[i].home.height);
		printf("    Кількість годівниць: %d\n", birds[i].home.feeders);
		printf("    Наявність гнізда: %c\n", birds[i].home.has_nest);
		printf("  Стать: %s\n", birds[i].gender);
		printf("\n");
	}
}

// Функція для знаходження відсоткового відношення самок до самців у відділі
float get_gender_ratio(const Bird *birds, int num_birds)
{
	int males = 0;
	int females = 0;

	for (int i = 0; i < num_birds; i++) {
		if (strcmp(birds[i].gender, "чоловіча") == 0) {
			males++;
		} else if (strcmp(birds[i].gender, "жіноча") == 0) {
			females++;
		}
	}
	if (males + females > 0) {
		return (float)females / (float)(males + females) * 100.0f;
	} else {
		return 0.0;
	}
}
