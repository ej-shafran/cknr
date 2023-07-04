#include <stdio.h>

int main(void)
{
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("FAHR   CELSIUS\n\n");

	for (float fahr = 0; fahr <= 300; fahr += 20) {
		float celsius = ((fahr * 5.0) - 160.0) / 9.0;
		printf("%4.0f  %8.1f\n", fahr, celsius);
	}

	printf("\nCELSIUS   FAHR\n\n");

	for (float celsius = 0; celsius <= 150; celsius += 10) {
		float fahr = ((celsius * 9.0) + 160.0) / 5.0;
		printf("%7.0f  %5.1f\n", celsius, fahr);
	}
}
