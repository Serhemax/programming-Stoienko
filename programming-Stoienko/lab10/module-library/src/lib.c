/**
 * @file lib.c
 * @brief 
 *
 * @author Stoienko Srhii
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"

int find_nsd(first_number, second_number)
{
	int larger_number;
	int nsd = 1;

	if (second_number >= first_number) {
		larger_number = second_number;
	} else {
		larger_number = first_number;
	}

	for (int i = 1; i <= larger_number; i++) {
		if (first_number % i == 0 && second_number % i == 0) {
			nsd = i;
		}
	}

	return nsd;
}
