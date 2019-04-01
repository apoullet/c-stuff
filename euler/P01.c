#include <stdio.h>

int main() {
    int total = 0;

    for (int i = 0; i < 1000; i++) {
	if (i % 3 == 0 || i % 5 == 0)
	    total += i;
    }

    printf("The sum of all the multiples of 3 and 5 below 1,000 is %d\n", total);

    return 0;
}
