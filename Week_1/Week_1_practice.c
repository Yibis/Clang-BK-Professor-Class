#include <stdio.h>
#include <stdlib.h>

int main() {
	int quantity;
	int stock[100];
	int sale[100];
	int id;

	printf("상품 개수(종류) 입력(1~100사이) : ");
	scanf_s("%d", &quantity);

	printf("상품 별 입고수량 입력 : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &stock[i]);
	}

	printf("상품 별 판매수량 입력 : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &sale[i]);
	}

	printf("ID입력 : ");
	scanf_s("%d",&id);
	printf("%d\n", stock[id - 1] - sale[id - 1]);


	for (int i = 0; i < quantity; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

}