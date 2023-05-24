/**
 * @file lib.c
 * @brief 
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include "lib.h"

void get_digits(const char *string, int *string_dig)
{
	int idx = 0;
	for (int i = 0; (unsigned long)i < strlen(string); i++) {
		if (isdigit(*(string + i))) {
			*(string_dig + idx) = (*(string + i) - '0');
			idx++;
		}
	}
}
void get_numbers(const char *string, int *string_num)
{
	int in_number = 0;
	int jjj = 0;
	int num = 0;
	int idx = 0;

	for (int i = 0; (unsigned long)i < strlen(string); i++) {
		if (isdigit(*(string + i))) {
			num = *(string + i) - '0';
			for (jjj = i + 1; (unsigned long)jjj < strlen(string) &&
					  isdigit(*(string + jjj));
			     jjj++) {
				num = num * 10 + (*(string + jjj) - '0');
			}
			*(string_num + idx) = num;
			idx++;
			i = jjj;
		}
	}
}
