#include <stdio.h>

#define LINELIMIT 80 /* the "suggested" line limit, to try to stop at */

int getlnlimit(char s[], int limit);

/* "fold" long (larger than LINELIMIT) lines in input and print them on multiple lines */
int main(void)
{
	char line[LINELIMIT + 10];
	int len;
	while ((len = getlnlimit(line, LINELIMIT)) != 0)
		printf("%s", line);
}

/* getlnlimit: read a line of characters into `s`, stopping at a natural breakpoint around `limit` */
int getlnlimit(char s[], int limit)
{
	int hardmax = limit + 10;

	int i;
	char c = getchar();
	for (i = 0; i < hardmax && c != EOF && c != '\n'; ++i) {
		if (i > limit && (c == ' ' || c == '\t'))
			break;

		s[i] = c;
		c = getchar();
	}

	if (c != EOF) {
		s[i] = '\n';
		++i;
	}

	s[i] = '\0';

	return i;
}
