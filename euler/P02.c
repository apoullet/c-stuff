#include <stdio.h>

int main() {
    int a = 1, b = 2, next;
    int total = 2;

    while (next < 4000000) {
	next = a + b;

	if (next % 2 == 0)
	    total += next;

	a = b;
	b = next;
    }

    printf("The sum of all the even-valued terms in the fibonacci sequence that do not exceed 4,000,000 is %d\n", total);

    return 0;
}
