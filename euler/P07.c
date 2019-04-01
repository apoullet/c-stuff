#include <stdio.h>
#include <math.h>

int is_prime(int n);

int main() {
    int count = 1, current = 1;

    while (count < 10001) {
	current += 2;

	if (is_prime(current))
	    count++;
    }

    printf("The 10001st prime is %d\n", current);

    return 0;
}

int is_prime(int n) {
    if (n % 2 == 0 && n > 2)
	return 0;

    for (int f = 3; f <= sqrt(n); f += 2)
	if (n % f == 0) return 0;

    return 1;
}
