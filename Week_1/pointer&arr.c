#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void inputRandomArray(int* array, int size);
void printArray(int* array, int size);

int main() {
	srand(time(NULL));
	int number[SIZE];

	inputRandomArray(number/*&number[0]*/, SIZE);
	//for (int i = 0; i < SIZE; i++) {
	//	number[i] = rand() % 100 + 1;
	//}

	printArray(number, SIZE);
	//for (int i = 0; i < SIZE; i++) {
	//	printf("%3d\t", number[i]);
	//	if ((i + 1) % 10 == 0) printf("\n");
	//}
}

void inputRandomArray(/*int array[]*/int* array, int size) {
	for (int i = 0; i < size; i++) {
		/*array[i]*/*(array + i) = rand() % 100 + 1;
	}
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf("%3d\t", /*array[i]*/*(array + i));
		if ((i + 1) % 10 == 0) printf("\n");
	}
}