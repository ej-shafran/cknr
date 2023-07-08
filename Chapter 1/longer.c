#include <stdio.h>

#define MAXLINE 1000 /* the maximum size accepted for a line */

int getln(char line[], int limit);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0) {
		if (len > 80) {
			printf("%s", line);

			int tmp = len;
			while (tmp == MAXLINE - 1) {
				tmp = getln(line, MAXLINE);
				len += tmp;
				printf("%s", line);
			}
		}
	}
}

int getln(char line[], int limit)
{
	int i;
	char c = getchar();
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
