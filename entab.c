#include <stdio.h>

#define TABSTOP 2 /* the symbolic parameter for number of spaces in a tab */

void printspaces(int spaces);

int main(void)
{
	int spaces = 0;
	char c;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++spaces;

		if (spaces == TABSTOP) {
			putchar('\t');
			spaces = 0;
		}

		if (c != ' ') {
			if (spaces > 0)
				printspaces(spaces);

			spaces = 0;

			putchar(c);
		}
	}
}

void printspaces(int spaces)
{
	for (int i = 0; i < spaces; ++i) {
		putchar(' ');
	}
}
