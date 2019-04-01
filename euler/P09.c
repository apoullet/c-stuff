#include <stdio.h>
#include <math.h>

int main() {
    for (int a = 0; a < 500; a++) {
	for (int b = a + 1; b < 500; b++) {
	    int c = 1000 - a - b;

	    if (a * a + b * b == c * c) {
		printf("%d x %d x %d = %d", a, b, c, a*b*c);
		return 0;
	    }
	}
    }

    return 0;
}
