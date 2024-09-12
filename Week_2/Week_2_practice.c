#include <stdio.h>
#include <stdlib.h>

int main() {
	int quantity;
	int stock[100];
	int sale[100];
	int totalStock = 0;
	int totalSale = 0;
	int minSale = 0, maxSale = 0;
	int temp;

	printf("상품 개수(종류) 입력(1~100사이) : ");
	scanf_s("%d", &quantity);

	printf("상품 별 입고수량 입력 : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &stock[i]);
		totalStock += stock[i];
	}

	printf("상품 별 판매수량 입력 : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &sale[i]);
		totalSale += sale[i];

		if (sale[minSale] > sale[i]) minSale = i;
		if (sale[maxSale] < sale[i]) maxSale = i;
	}

	printf("\n재고수량 : ");
	for (int i = 0; i < quantity; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

	double saleRatio= ((double)totalSale / totalStock) * 100;
	printf("\n총 판매량 : %d (판매율: %.2f%%)\n", totalSale, saleRatio);

	printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxSale + 1, sale[maxSale]);
	printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minSale + 1, sale[minSale]);

	for (int i = 0; i < quantity; i++) {
		if (stock[i] - sale[i] <= 2) {
			printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i] - sale[i]);
		}
	}
}
