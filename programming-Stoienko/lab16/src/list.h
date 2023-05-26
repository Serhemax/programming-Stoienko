#include "entity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write_birds_to_file(const char *filename, const Bird *birds,
                         int num_birds);
// Функція для знаходження відсоткового відношення самок до самців у відділі
float get_gender_ratio(const Bird *birds, int num_birds);
void add_bird(Bird **birds, int *num_birds, Bird new_bird);
void remove_bird_in(Bird **birds, int *num_birds, int idx);
void sort(Bird **birds, int *num_birds);
int compare_birds_age(const void *age1, const void *age2);
