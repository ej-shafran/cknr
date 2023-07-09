#include <stdio.h>

#define NOT_FOUND \
	-1 /* the result from `any` if `s1` has no characters from `s2` */
#define MAXLINE 1000 /* the maximum accepted length for a line */

int any(char s1[], char s2[]);
void getln(char s[], int limit);

/* print the first location in `s1` where any character from `s2` occurs */
int main(void)
{
	char s1[MAXLINE], s2[MAXLINE];

	getln(s1, MAXLINE);
	getln(s2, MAXLINE);

	int result = any(s1, s2);

	printf("result at index %d\n", result);
}

/* any: returns the first location in `s1` where any character from `s2` occurs */
int any(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0'; ++i) {
		for (int k = 0; s2[k] != '\0'; ++k) {
			if (s1[i] == s2[k])
				return i;
		}
	}

	return NOT_FOUND;
}

/* getln: util to get a line from stdin */
void getln(char s[], int limit)
{
	int i = 0;
	char c;
	while (i < limit - 1 && (c = getchar()) != '\n' && c != EOF)
		s[i++] = c;

	s[i] = '\0';
}
