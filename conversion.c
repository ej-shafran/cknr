#include <stdio.h>

float fahr_to_celsius(float fahr);
float celsius_to_fahr(float celsius);

int main(void)
{
	int lower, upper, step;

	printf("FAHR   CELSIUS\n\n");

	for (float fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%4.0f  %8.1f\n", fahr, fahr_to_celsius(fahr));
	}

	printf("\nCELSIUS   FAHR\n\n");

	for (float celsius = 150; celsius >= 0; celsius -= 10) {
		printf("%7.0f  %5.1f\n", celsius, celsius_to_fahr(celsius));
	}
}

float fahr_to_celsius(float fahr)
{
	return ((fahr * 5.0) - 160.0) / 9.0;
}

float celsius_to_fahr(float celsius)
{
	return ((celsius * 9.0) + 160.0) / 5.0;
}
