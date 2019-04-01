#include <stdio.h>
#include <math.h>

int not_palyndrome(int n);

int main() {
    int largest = 0;

    for (int a = 300; a < 999; a++) {
	for (int b = 300; b < 999; b++) {
	    int product = a * b;

	    if (!not_palyndrome(product))
		largest = (product > largest) ? product : largest;
	}
    }

    printf("The largest palyndrome made by the product of two 3-digit numbers is %d\n", largest);

    return 0;
}

int not_palyndrome(int n) {
    int half = 0;

    for (int i = 3; i > 0; i--) {
	int remainder = n % 10;
	n /= 10;

	if (remainder > 0) 
	    half += remainder * (int) pow(10, i);
    }

    return n - half / 10;
}
