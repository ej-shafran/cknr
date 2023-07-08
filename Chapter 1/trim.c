#include <stdio.h>

#define MAXLINE 1000 /* maximum size of accepted input */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int getln(char line[], int limit);

/* re-print input, trimming any trailing tabs and spaces and removing entirely blank lines */
int main(void)
{
	char line[MAXLINE];
	int len;

	while ((len = getln(line, MAXLINE)) > 0) {
		int state = OUT;

		/* start at len - 2 to cut out '\0' and '\n' */
		for (int i = len - 2; i >= 0; --i) {
			if (line[i] != '\t' && line[i] != ' ')
				state = IN;

			/* use '\0' to shorten the text */
			if (state == OUT)
				line[i] = '\0';
		}

		/* skip lines that are just '\n' */
		if (len != 1)
			printf("%s\n", line);
	}
}

int getln(char line[], int limit)
{
	char c = getchar();
	int i;
	for (i = 0; i < limit - 1 && c != EOF && c != '\n'; ++i) {
		line[i] = c;
		c = getchar();
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}
