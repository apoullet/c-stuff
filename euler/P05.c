#include <stdio.h>
#include <math.h>

int is_prime(int n);
int kewl_multiple(int n);

int main() {
    int n = 20;
    int result = kewl_multiple(n);

    printf("The kewl multiple for all the numbers up to %d is %d\n", n, result);

    return 0;
}

int is_prime(int n) {
    if (n % 2 == 0 && n > 2)
	return 0;

    for (int f = 3; f <= sqrt((double) n); f++) {
	if (n % f == 0)
	    return 0;
    }

    return 1;
}

int kewl_multiple(int n) {
    int multiple = 1, count = 1;

    do {
	multiple *= 2;
    } while (pow(2, ++count) < n);

    for (int f = 3; f < n; f += 2) {
	if (is_prime(f)) {
	    count = 1;

	    do {
		multiple *= f;
	    } while (pow(f, ++count) < n);
	}
    }

    return multiple;
} 
