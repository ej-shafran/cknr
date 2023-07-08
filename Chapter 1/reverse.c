#include <stdio.h>

#define MAXLINE 1000 /* the max accepted size for a line */

void reverse(char s[]);
int getln(char line[], int limit);

int main(void)
{
	char line[MAXLINE];
	int len;

	while ((len = getln(line, MAXLINE)) > 0) {
		/* remove the trailing '\n' for better printing */
		line[len - 1] = '\0';
		reverse(line);

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
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';

	return i;
}

void reverse(char s[])
{
	int len = 0;
	while (s[len] != '\0')
		++len;

	/* don't count '\0' in the length */
	--len;

	for (int i = 0; i < len / 2; ++i) {
		char tmp = s[i];
		s[i] = s[len - i];
		s[len - i] = tmp;
	}
}
