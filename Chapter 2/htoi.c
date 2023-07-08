#include <stdio.h>
#include <ctype.h>

#define INPUT_LENGTH 6 /* the maximum accepted input length */

int htoi(const char s[]);

int main(void)
{
	char s[INPUT_LENGTH];

	for (int i = 0; i < INPUT_LENGTH; ++i)
		s[i] = getchar();

	printf("%d\n", htoi(s));
}

/* htoi: converts a string of hexadecimal digits into its integer representation */
int htoi(const char s[])
{
	int result = 0;

	for (int i = 0; isxdigit(s[i]); ++i) {
		int val;
		if (isdigit(s[i]))
			val = s[i] - '0';
		else
			val = tolower(s[i]) - 'a' + 10;

		result = 16 * result + val;
	}

	return result;
}
