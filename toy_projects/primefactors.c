#include <stdio.h>
#include <math.h>

int is_prime(double n);
int * get_prime_factors(int n);

int main() {

    return 0;
}

int is_prime(double n) {
    if (n % 2 == 0)
	return 0;

    for (double i = 3; i < sqrt(n); i += 2) {
	if (n % i == 0)
	    return 0;
    }

    return 1;
}

int * get_prime_factors(int n) {
    int * prime_factors = malloc(sizeof(int) * 2 * sqrt(double(n)));

    for (int i = 0; i < n; i++) {
	
    }

    return prime_factors;
}
