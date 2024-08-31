#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
    srand(time(NULL));
    int number[SIZE];
    int total = 0;
    int max, min;
    float avg = 0.0;

    for (int i = 0; i < SIZE; i++) {
        number[i] = (rand() % SIZE) + 1;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%3d\t", number[i]);

        if ((i + 1) % 10 == 0)  printf("\n");
    }

    for (int i = 0; i < SIZE; i++) {
        total += number[i];
    }
    //avg = total / 10.0;                       ����� �Ǽ������� �ֱ�
    //avg = (float)total / 10;                  ������ �Ǽ������� �ٲٱ�
    avg = (float)total / SIZE;

    //�迭�� �� Ȱ��
    max = number[0];                          
    min = number[0];

    for (int i = 0; i < SIZE; i++) {
        if (max < number[i]) max = number[i];
        if (min > number[i]) min = number[i];
    }
    printf("avg = %f, max = %d, min = %d", avg, max, min);

    printf("\n");
    //�迭�� �ε��� Ȱ��
    max = 0;                                 
    min = 0;

    for (int i = 0; i < SIZE; i++) {
        if (number[max] < number[i]) max = i;
        if (number[min] > number[i]) min = i;
    }
    printf("avg = %f, max = %d, min = %d", avg, number[max], number[min]);

    return 0;
}