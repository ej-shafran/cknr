#include <stdio.h>

int main(void)
{
	int i = 0;
	int limit = 1000;
	char c;
	char s[limit];

	int shouldbreak = 0;

	while (!shouldbreak) {
		c = getchar();

		if ((c == '\n') == (c == EOF) != 0) {
			s[i] = c;
			++i;
			shouldbreak = !(i < limit - 1);
		} else {
			shouldbreak = 1;
		}
	}

	printf("%s\n", s);
}
