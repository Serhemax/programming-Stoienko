#include "list.h"

void write_birds_to_file(const char *filename, const Bird *birds,
                         int num_birds) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Помилка відкриття файлу.\n");
    return;
  }

  for (int i = 0; i < num_birds; i++) {
    fprintf(file, "%d %s %d %d %d %d %d %s\n", birds[i].is_ringed,
            birds[i].type, birds[i].age, birds[i].home.area,
            birds[i].home.height, birds[i].home.feeders, birds[i].home.has_nest,
            birds[i].gender);
  }

  fclose(file);
}

float get_gender_ratio(const Bird *birds, int num_birds) {
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

void add_bird(Bird **birds, int *num_birds, Bird new_bird) {
  Bird *new_list_birds = malloc((size_t)(*num_birds + 1) * sizeof(Bird));
  // Копіювання вмісту старого масиву до нового
  memcpy(new_list_birds, *birds, ((size_t)*num_birds * sizeof(Bird)));
  // Додавання нового елемента
  new_list_birds[*num_birds] = new_bird;
  // Збільшення лічильника
  (*num_birds)++;
  // Звільнення пам'яті, виділеної для старого масиву
  free(*birds);
  // Присвоєння нової адреси масиву
  *birds = new_list_birds;
}

void remove_bird_in(Bird **birds, int *num_birds, int idx) {
  if (idx < 0 || idx >= *num_birds) {
    fprintf(stderr, "Error: Index out of range\n");
    exit(EXIT_FAILURE);
  }

  free(((*birds)[idx].type));
  free(((*birds)[idx].gender));

  for (int i = idx; i < *num_birds - 1; i++) {
    (*birds)[i] = (*birds)[i + 1];
  }

  *num_birds -= 1;
}

int compare_birds_age(const void *age1, const void *age2) {
  const Bird *bird_age1 = (const Bird *)age1;
  const Bird *bird_age2 = (const Bird *)age2;
  return bird_age1->age - bird_age2->age;
}
