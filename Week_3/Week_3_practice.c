#include <stdio.h>
#include <stdlib.h>
#define GOODS 5

void stockGoods(int* stock);
void saleGoods(int* sale);
void statusGoods(int* stock, int* sale);
int main() {
	int stock[GOODS] = { 0 };
	int sale[GOODS] = { 0 };
	int num;

	do {
		printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 상품현황, 4. 종료)\n");
		scanf_s("%d", &num);
		printf("\n");

		switch (num) {
		case 1:
			stockGoods(stock);
			break;
		case 2:
			saleGoods(sale);
			break;
		case 3:
			statusGoods(stock, sale);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("다시 입력해주세요.\n");
			break;
		}
		printf("\n");
	} while (num != 4);
}


void stockGoods(int* stock) {
	int num, id, temp;

	printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택\n1 2 선택 : ");
	scanf_s("%d", &num);

	if (num == 1) {
		printf("상품 별 입고수량 입력 : ");
		for (int i = 0; i < GOODS; i++) {
			scanf_s("%d", &temp);
			stock[i] += temp;
		}
	} else if (num == 2) {
		printf("상품ID : ");
		scanf_s("%d", &id);
		if (id <= GOODS && id >= 1) {
			printf("입고수량 입력 : ");
			scanf_s("%d", &temp);
			stock[id - 1] += temp;
		}
		else {
			printf("잘못된 입력입니다.");
		}
	} else {
		printf("잘못된 입력입니다.");
	}

}

void saleGoods(int* sale) {
	int num, id, temp;

	printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택\n1 2 선택 : ");
	scanf_s("%d", &num);

	if (num == 1) {
		printf("상품 별 판매수량 입력 : ");
		for (int i = 0; i < GOODS; i++) {
			scanf_s("%d", &temp);
			sale[i] += temp;
		}
	} else if (num == 2) {
		printf("상품ID : ");
		scanf_s("%d", &id);
		if (id <= GOODS && id >= 1) {
			printf("판매수량 입력 : ");
			scanf_s("%d", &temp);
			sale[id - 1] += temp;
		} else {
			printf("잘못된 입력입니다.");
		}
	} else {
		printf("잘못된 입력입니다.");
	}
}

void statusGoods(int* stock, int* sale) {
	int totalStock = 0, totalSale = 0, minSale = 0, maxSale = 0;
	int temp;

	for (int i = 0; i < GOODS; i++) {
		totalSale += sale[i];
		totalStock += stock[i];

		if (sale[minSale] > sale[i]) minSale = i;
		if (sale[maxSale] < sale[i]) maxSale = i;
	}

	printf("재고수량 : ");
	for (int i = 0; i < GOODS; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n총 판매량 : %d (판매율: %.2f%%)\n", totalSale, saleRatio);

	printf("가장 많이 판매된 상품: ID %d, 판매량 %d\n", maxSale + 1, sale[maxSale]);
	printf("가장 적게 판매된 상품: ID %d, 판매량 %d\n", minSale + 1, sale[minSale]);

	for (int i = 0; i < GOODS; i++) {
		if (stock[i] - sale[i] <= 2) {
			printf("상품 ID %d: 재고부족(%d)\n", i + 1, stock[i] - sale[i]);
		}
	}
}
