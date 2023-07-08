#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define PARENS 0 /* the index for unbalanced () within the issues array */
#define BRACES 1 /* the index for unbalanced {} within the issues array */
#define BRACKETS 2 /* the index for unbalanced [] within the issues array */
#define ISSUE_COUNT 3 /* the total amount of possible issues */

/*
 * check a C program for Unbalanced parens, brackets, and braces,
 * while minding quotes and comments
 */
int main(void)
{
	char prev = getchar();
	char cur = getchar();

	int linecomment = FALSE;
	int blockcomment = FALSE;
	int doublequotes = FALSE;
	int singlequotes = FALSE;

	int issues[ISSUE_COUNT];
	for (int i = 0; i < ISSUE_COUNT; ++i)
		issues[i] = 0;

	int escape = FALSE;

	while (prev != EOF) {
		int ignore = linecomment || blockcomment || doublequotes ||
			     singlequotes;

		if (!ignore && prev == '/' && cur == '/')
			blockcomment = TRUE;
		else if (blockcomment && prev == '\n')
			blockcomment = FALSE;

		if (!ignore && prev == '/' && cur == '*')
			linecomment = TRUE;
		else if (linecomment && prev == '*' && cur == '/')
			linecomment = FALSE;

		if (!ignore && prev == '"')
			doublequotes = TRUE;
		else if (doublequotes && !escape && prev == '"')
			doublequotes = FALSE;

		if (!ignore && prev == '\'')
			singlequotes = TRUE;
		else if (singlequotes && !escape && prev == '\'')
			singlequotes = FALSE;

		if (!ignore) {
			issues[PARENS] += (prev == '(') - (prev == ')');
			issues[BRACES] += (prev == '{') - (prev == '}');
			issues[BRACKETS] += (prev == '[') - (prev == ']');
		}

		escape = !escape && prev == '\\';

		prev = cur;
		cur = getchar();
	}

	if (issues[PARENS] != 0)
		printf("Unbalanced parentheses -> ()\n");
	if (issues[BRACES] != 0)
		printf("Unbalanced braces -> {}\n");
	if (issues[BRACKETS] != 0)
		printf("Unbalanced brackets -> []\n");

	int issues_found = 0;
	for (int i = 0; i < ISSUE_COUNT; ++i)
		issues_found += issues[i];

	if (issues_found == 0)
		printf("No issues found!\n");
}
