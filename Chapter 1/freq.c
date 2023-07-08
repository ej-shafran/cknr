#include <stdio.h>

#define UPPER 26 /* number of lowercase letters */

int main(void)
{
	char c;

	int letters[UPPER];

	for (int i = 0; i < UPPER; i++)
		letters[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z')
			++letters[c - 'a'];
	}

	int max = 0;
	for (int i = 0; i < UPPER; i++) {
		if (letters[i] > max)
			max = letters[i];
	}

	for (int i = max; i > 0; i--) {
		printf("%3d ", i);
		for (int j = 0; j < UPPER; j++) {
			if (letters[j] >= i)
				printf(" | ");
			else
				printf("   ");
		}
		printf("\n");
	}

	printf("   ");
	for (int i = 0; i < UPPER; i++) {
		printf("%2c ", i + 'a');
	}
}
