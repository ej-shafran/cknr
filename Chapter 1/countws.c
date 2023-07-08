#include <stdio.h>

int main(void)
{
	char c;
	int n = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == '\t' || c == ' ') {
			n++;
		}
	}

	printf("%d\n", n);
}
