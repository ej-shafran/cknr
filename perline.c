#include <stdio.h>

int main(void)
{
	char c;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			putchar('\n');
		} else {
			putchar(c);
		}
	}
}
