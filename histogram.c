#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define UPPER 20 /* highest length we check for */

int main(void)
{
	int state = OUT;
	int lengths[UPPER];
	int length = 0;

	for (int i = 0; i < UPPER; i++)
		lengths[i] = 0;

	char c;
	while ((c = getchar()) != EOF) {
		int is_whitespace = c == ' ' || c == '\n' || c == '\t';

		if (length == UPPER || (is_whitespace && state == IN)) {
			++lengths[length - 1];
			length = 0;
		}

		if (is_whitespace) {
			state = OUT;
		} else {
			state = IN;
			++length;
		}
	}

	int max = 0;
	for (int i = 0; i < UPPER; i++) {
		if (lengths[i] > max)
			max = lengths[i];
	}

	for (int i = max; i > 0; i--) {
		for (int j = 0; j < UPPER; j++) {
			if (lengths[j] + 1 > i)
				printf(" | ");
			else
				printf("   ");
		}
		printf("\n");
	}

	for (int i = 0; i < UPPER - 1; i++) {
		printf("%2d ", i + 1);
	}
	printf("%2d+\n", UPPER);
}
