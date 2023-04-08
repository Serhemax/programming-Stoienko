#include <stdio.h>

int main()
{
	float variable_y = 0.0f;
	float variable_x = -0.5f;
	// float variable_x = 2.0f;
	// float variable_x = -2.0f;
	//Згідно з малюнком, якщо х менше -1, то графіком буде y = -1 / x
	if (variable_x < -1) {
		variable_y = -1.0f / variable_x;
	}

	//Якщо х знаходиться між -1 та 1, то графіком буде парабола
	else if (variable_x >= -1 && variable_x <= 1) {
		variable_y = variable_x * variable_x;
	}

	//Якщо х є більшим від 1, то графіком функції буде пряма лінія,
	//перпендикулярна осі х
	else {
		variable_y = 1.0f;
	}

	return (int)variable_y;
}
