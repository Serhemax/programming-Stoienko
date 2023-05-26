
#include "entity.h"

Bird *read_bird(const char *filename, int *num_birds) {
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

// Функція для виведення масиву птахів на екран
void print_birds(const Bird *birds, int num_birds) {
  for (int i = 0; i < num_birds; i++) {
    printf("Птах %d:\n", i + 1);
    printf("  Чи окольцьований: %d\n", birds[i].is_ringed);
    printf("  Назва виду: %s\n", birds[i].type);
    printf("  Вік: %d місяців\n", birds[i].age);
    printf("  Домівка:\n");
    printf("    Площа: %d кв. см\n", birds[i].home.area);
    printf("    Висота: %d см\n", birds[i].home.height);
    printf("    Кількість годівниць: %d\n", birds[i].home.feeders);
    printf("    Наявність гнізда: %d\n", birds[i].home.has_nest);
    printf("  Стать: %s\n", birds[i].gender);
    printf("\n");
  }
}
