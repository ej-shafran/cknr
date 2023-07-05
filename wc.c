#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* 
 * Q. How would you test this program? 
 * A. Run it with a bunch of different inputs, specifically with trickier inputs
 *
 * Q. What kind of inputs are likely to uncover bugs, if there are any?
 * A. Ones with consecutive whitespace (especially newlines)
 */

/* count lines, words, and characters in input */
int main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((c = getchar()) != EOF) {
		++nc;

		if (c == '\n')
			++nl;

		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}
