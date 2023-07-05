#include <stdio.h>

#define TABSIZE 2 /* the symbolic parameter for spaces in a tab */

int main(void)
{
	char c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (int i = 0; i < TABSIZE; ++i) {
				putchar(' ');
			}
		} else {
			putchar(c);
		}
	}
}
