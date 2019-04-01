#include <stdio.h>
#include <stdlib.h>

int * fibonacci(int limit);

int main() {
    int limit = 20;

    int * sequence = fibonacci(limit);

    printf("The first %d numbers of the fibonacci sequence are: \n", limit);

    for (int i = 0; i < limit-1; i++)
	printf("%d, ", sequence[i]);

    printf("%d\n", sequence[limit-1]);

    free(sequence);

    return 0;
}

int * fibonacci(int limit) {
    int a = 1, b = 1, next;

    int * sequence = malloc(sizeof(int) * limit);

    sequence[0] = a;
    sequence[1] = b;
    
    for (int i = 2; i < limit; i++) {
	next = a + b;

	sequence[i] = next;

	b = a;
	a = next;
    }

    return sequence;
}
