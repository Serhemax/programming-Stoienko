/**
 * @file lib.c
 * @brief 
 *
 * @author Stoienko Serhii.
 * @date 16-apr-2023
 */

#include "lib.h"

void create_wave(int amplitude, int period, char symbol, FILE *fp)
{
	// Calculate the horizontal displacement of each character
	double delta_x = 2.0 * M_PI / (double)period;

	// Iterate through each row of the wave
	for (int y = amplitude; y >= -amplitude; y--) {
		// Iterate through each column of the wave
		for (int x = 0; x < period; x++) {
			// Calculate the horizontal displacement of this character
			double alpha = delta_x * (double)x;
			double displacement = amplitude * sin(alpha);

			// Determine whether to output the fill character or a space
			if (displacement >= (double)y - 0.5 &&
			    displacement <= (double)y + 0.5) {
				fputc(symbol, fp);
			} else {
				fputc(' ', fp);
			}
		}

		// End the row with a newline character
		fputc('\n', fp);
	}
}
