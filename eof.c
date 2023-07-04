#include <stdio.h>

int main(void)
{
	char c;

	while (1) {
		c = getchar();

		printf("%c\n", c);
		printf("%d\n", c != EOF);

		if (c == EOF)
			break;
	}
}
