#include <stdio.h>
#include <math.h>

int main() {
    double sum_of_square = 0, square_of_sum = 0;

    for (int n = 1; n <= 100; n++) {
	sum_of_square += pow(n, 2);
	square_of_sum += n;
    }

    square_of_sum = pow(square_of_sum, 2);

    printf("%f\n", square_of_sum - sum_of_square);

    return 0;
}
