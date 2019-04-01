#include <stdio.h>
#include <math.h>

int is_prime(long n);
long largest_prime_factor(long n);

int main() {
    long number = 600851475143;

    printf("The largest prime factor or %ld is %ld\n", number, largest_prime_factor(number));

    return 0;
}

int is_prime(long n) {
    if (n > 2 && n % 2 == 0)
	return 0;

    for (long f = 3; f < sqrt((double) n); f += 2)
	if (n % f == 0) return 0;
    
    return 1;
}

long largest_prime_factor(long n) {
    long largest, current_factor = 3;

    while (n > 1) {
	if (n % 2 == 0) {
	    largest = 2;
	    n /= 2;
	    continue;
	}

	if (n % current_factor == 0) {
	    if (is_prime(current_factor))
		largest = current_factor;

	    n /= current_factor;
	    continue;
	}

	current_factor += 2;
    }

    return largest;
}
