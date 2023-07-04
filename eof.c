#include <stdio.h>

int main(void)
{
	char c;

	printf("%d\n", EOF);

	while (1) {
		c = getchar();

		printf("%c\n", c);
		printf("%d\n", c != EOF);

		if (c == EOF)
			break;
	}
}
