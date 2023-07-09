#include <stdio.h>

#define MAXLINE 1000 /* the maximum accepted length for a line */

enum bool { false, true };

void squeeze(char s1[], char s2[]);
void getln(char s[], int limit);

/* delete all characters from `s1` which exist in `s2` */
int main(void)
{
	char s1[MAXLINE], s2[MAXLINE];
	getln(s1, MAXLINE);
	getln(s2, MAXLINE);

	squeeze(s1, s2);
	printf("s1: %s\n", s1);
}

/* squeeze: delete all characters from `s1` which exist in `s2` */
void squeeze(char s1[], char s2[])
{
	int j, i;
	for (i = j = 0; s1[i] != '\0'; ++i) {
		enum bool duplicate = false;

		for (int k = 0; s2[k] != '\0'; ++k)
			duplicate = duplicate || (s1[i] == s2[k]);

		if (!duplicate)
			s1[j++] = s1[i];
	}

	s1[j] = '\0';
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
