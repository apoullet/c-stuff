#include <stdio.h>
#include <stdlib.h>

int * primes_up_to(int n);

int main() {
    int n = 2000000;

    int * primes = primes_up_to(n);
    long total   = 2;

    for (int i = 0; i < n/2-1; i++)
	total += primes[i];
    
    printf("The sum of all the primes below %d is %ld", n, total);

    return 0;
}

int * primes_up_to(int n) {
    int * numbers = malloc(sizeof(long) * n / 2 - 1);
    long prime_found = 1, index = 0;

    for (long i = 3; i < n; i += 2)
	numbers[(i-3)/2] = i;

    while (prime_found) {
	prime_found = 0;

	for (long i = index; i < n; i++) {
	    if (numbers[i] != 0) {
		prime_found = numbers[i];
		index = i + 1;

		for (long j = prime_found*prime_found; j > 0 && j < n; j += (2*prime_found))
		    numbers[(j-3)/2] = 0;
	    }
	}
    }

    return numbers;
}
