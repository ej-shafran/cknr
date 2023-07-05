#include <stdio.h>

#define QUOTES 2 /* inside '"', ignore any comments */
#define IN 1 /* inside a comment, don't print */
#define OUT 0 /* outside of a comment, print and watch for comments */

int main(void)
{
	int status = OUT;
	char prev, cur;

	cur = getchar();
	if (cur == EOF)
		return 0;

	prev = cur;
	cur = getchar();

	while (prev != EOF) {
		if (status == OUT) {
			if (prev == '"')
				status = QUOTES;

			if (prev == '/' && cur == '*')
				status = IN;
			else
				putchar(prev);
		} else if (status == QUOTES) {
			if (prev == '"')
				status = OUT;
			putchar(prev);
		} else if (prev == '*' && cur == '/') {
			status = OUT;

			/* clear out the last '/' */
			prev = cur;
			cur = getchar();
		}

		prev = cur;
		cur = getchar();
	}
}
