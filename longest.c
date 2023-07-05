#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getln(char line[], int limit);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getln(line, MAXLINE)) > 0) {
		int tmp = len;
		while (tmp == MAXLINE - 1) {
			tmp = getln(line, MAXLINE);
			len = len + tmp;
		}

		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("The longest line was %d characters long.\n", max);
		printf("The line was:\n");
		printf("%s", longest);
	} else {
		printf("Invalid input.");
	}

	return 0;
}

/* getln: read a line into `line`, return the length */
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

/* copy: copy `from` into `to`; assume `to` is big enough */
void copy(char to[], char from[])
{
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
