#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	char c;
	bool isws = false;

	while ((c = getchar()) != EOF) {
		if (c != '\n' || !isws) {
			putchar(c);
		}

		if (c == '\n') {
			isws = true;
		} else {
			isws = false;
		}
	}
}
