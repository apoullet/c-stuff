#include <stdio.h>
#include <stdlib.h>

int findGreatestProduct(int arr[][20], int rows, int cols);

int main() {
    FILE * file;
    int row = 0, col = 0;

    int numbers[20][20];

    file = fopen("Resources/P11.txt", "r");

    while (!feof(file)) {
	fscanf(file, "%d", &numbers[row][col]);

	if (col == 19) {
	    row++;
	    col = 0;
	} else {
	    col++;
	}
    }

    int greatestProduct = findGreatestProduct(numbers, 20, 20);

    printf("The greatest product of four adjacent numbers in the same direction in the 20x20 grid is %d", greatestProduct);

    return 0;
}

int findGreatestProduct(int arr[][20], int rows, int cols) {
    int maxVertical = 0, maxHorizontal = 0, maxDiagonalUp = 0, maxDiagonalDown = 0;
    
    // Vertical product
    for (int x = 0; x < cols; x++) {
	for (int y = 0; y < rows-4; y++) {
	    int current = 1;

	    for (int i = 0; i < 4; i++)
		current *= arr[y+i][x];

	    if (current > maxVertical)
		maxVertical = current;
	}
    }

    // Horizontal product
    for (int y = 0; y < cols; y++) {
	for (int x = 0; x < rows-4; x++) {
	    int current = 1;

	    for (int i = 0; i < 4; i++)
		current *= arr[y][x+i];

	    if (current > maxHorizontal)
		maxHorizontal = current;
	}
    }

    // Diagonal up product
    for (int y = 3; y < cols; y++) {
	for (int x = 0; x < rows-4; x++) {
	    int current = 1;

	    for (int i = 0; i < 4; i++)
		current *= arr[y-i][x+i];

	    if (current > maxDiagonalUp)
		maxDiagonalUp = current;
	}
    }

    // Diagonal down product
    for (int y = 0; y < cols-4; y++) {
	for (int x = 3; x < rows; x++) {
	    int current = 1;

	    for (int i = 0; i < 4; i++)
		current *= arr[y+i][x+i];

	    if (current > maxDiagonalDown)
		maxDiagonalDown = current;
	}
    }

    int products[4] = { maxVertical, maxHorizontal, maxDiagonalUp, maxDiagonalDown };

    int max = 0;

    for (int i = 0; i < 4; i++) {
	if (products[i] > max)
	    max = products[i];
    }
    
    return max;
}
