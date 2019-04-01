#include <stdio.h>
#include <stdlib.h>

void insert_back(int * arr, size_t length, int element);
void copy_array(int * from, int * to, size_t length);
long mul(int * arr, size_t length);

int main() {
    FILE * file;
    int number;

    file = fopen("Resources/P08.txt", "r");

    int window_size = 13;

    int best[window_size], window[window_size];

    for (int i = 0; i < window_size; i++) {
	fscanf(file, "%d", &number);

	window[i] = number;
    }

    long current, max = mul(window, window_size);

    while (!feof(file)) {
	fscanf(file, "%d", &number);

	insert_back(window, window_size, number);

	current = mul(window, window_size);

	if (current > max) {
	    max = current;
	    copy_array(window, best, window_size);
	}
    }

    printf("The %d adjacent digits in the 1000-digit number that have the greatest product are: ", window_size);

    for (int i = 0; i < window_size-1; i++) {
	printf("%d x ", best[i]);
    }

    printf("%d = %ld.\n", best[window_size-1], max);

    fclose(file);

    return 0;
}

void insert_back(int * arr, size_t length, int element) {
    for (int i = 0; i < length-1; i++)
	arr[i] = arr[i+1];

    arr[length-1] = element;
}

void copy_array(int * from, int * to, size_t length) {
    for (int i = 0; i < length; i++)
	to[i] = from[i];
}

long mul(int * arr, size_t length) {
    long product = 1;

    for (int i = 0; i < length; i++)
	product *= (long) arr[i];

    return product;
}
