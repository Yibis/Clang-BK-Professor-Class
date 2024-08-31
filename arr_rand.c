#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int number[10];

    for (int i = 0; i < 10; i++) {
        number[i] = (rand() % 100) + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("number = %d\n", number[i]);
    }

    return 0;
}