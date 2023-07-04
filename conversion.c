#include <stdio.h>

int main(void)
{
	float celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("FAHR  CELSIUS\n\n");

	for (float fahr = lower; fahr <= upper; fahr += step) {
		celsius = ((fahr * 5.0) - 160.0) / 9.0;
		printf("%4.0f %8.1f\n", fahr, celsius);
	}
}
