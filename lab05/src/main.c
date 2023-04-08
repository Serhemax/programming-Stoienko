
#include <stdio.h>

int main()
{
	// create first and second number
	int first_number = 18;
	int second_number = 20;

	int larger_number;
	int nsd;

	//we need to check which of the numbers are larger
	//and assign new valuble to variable larger_number
	//for knowing, what number is larger for cycle for
	if (second_number >= first_number) {
		larger_number = second_number;
	} else {
		larger_number = first_number;
	}
	/*
	for (int some_number = 1; some_number <= larger_number; some_number++) {
		// if numbers are both evenly divisible by some_number, then 
		// some_number is common factor, the last some_number, that gonna be common
		// factor of the numbers, is largest
		if (first_number % some_number == 0 && 
		second_number % some_number == 0) {
			nsd = some_number;
		}
	}
*/
	int some_number = 1;

	/*	do {
		if (first_number % some_number == 0 &&\
		 second_number % some_number == 0) {
			nsd = some_number;
		}
		some_number++;
	} while (some_number <= larger_number);
*/
	while (some_number <= larger_number) {
		if (first_number % some_number == 0 &&
		    second_number % some_number == 0) {
			nsd = some_number;
		}
		some_number++;
	}

	return nsd;
}
