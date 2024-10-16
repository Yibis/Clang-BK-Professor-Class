#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define GOODS 5

typedef struct {
	int id;
	char name[100];
	int stock;
	int sale;
	int price;
} Goods;

void stockGoods(Goods* goods);
void saleGoods(Goods* goods);
void indStatusGoods(Goods* goods);
void allStatusGoods(Goods* goods);

int main() {
	Goods goods[GOODS] = { 0 };
	int num;


	do {
		printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 종료)\n");
		scanf_s("%d", &num);
		getchar();
		printf("\n");

		switch (num) {
		case 1:
			stockGoods(goods);
			break;
		case 2:
			saleGoods(goods);
			break;
		case 3:
			indStatusGoods(goods);
			break;
		case 4:
			allStatusGoods(goods);
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("다시 입력해주세요.\n");
			break;
		}
		printf("\n");
	} while (num != 5);
}


void stockGoods(Goods* goods) {
	int id, temp;

	printf("상품ID : ");
	scanf_s("%d", &id);
	goods[id - 1].id = id;
	printf("상품명 : ");
	getchar();
	gets_s(goods[id - 1].name, 100);
	printf("입고량 : ");
	scanf_s("%d", &temp);
	goods[id - 1].stock += temp;
	printf("판매가격 : ");
	scanf_s("%d", &goods[id - 1].price);
}

void saleGoods(Goods* goods) {
	int id, temp;

	printf("상품ID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("존재하지 않는 ID입니다.");
	else {
		printf("판매량 : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock < goods[id - 1].sale) printf("남은 재고 수량보다 많은 판매량입니다.");
		else goods[id - 1].sale += temp;
	}
}

void indStatusGoods(Goods* goods) {
	int id, temp;

	printf("상품ID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("존재하지 않는 ID입니다.");
	else {
		printf("상품명 : %s\n", goods[id - 1].name);
		printf("판매가격 : %d\n", goods[id - 1].price);
		printf("재고수량 : %d\n", goods[id - 1].stock - goods[id - 1].sale);
	}
}


void allStatusGoods(Goods* goods) {
	int totalStock = 0, totalSale = 0, minSale = 0, maxSale = 0;
	int temp;

	for (int i = 0; i < GOODS; i++) {
		totalStock += goods[i].stock;
		totalSale += goods[i].sale;

		if (goods[minSale].sale > goods[i].sale) minSale = i;
		if (goods[maxSale].sale < goods[i].sale) maxSale = i;
	}

	printf("재고수량 : ");
	for (int i = 0; i < GOODS; i++) {
		printf("ID %d : %d ", i+1, goods[i].stock - goods[i].sale);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n총 판매량 : %d (판매율: %.2f%%)\n", totalSale, saleRatio);
	
	temp = 0;
	for (int i = 0; i < GOODS; i++) temp += goods[i].price * goods[i].sale;
	printf("총 판매가 : %d원\n", temp);

	printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", maxSale + 1, goods[maxSale].name, goods[maxSale].sale);
	printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량 %d\n", minSale + 1, goods[minSale].name, goods[minSale].sale);

	for (int i = 0; i < GOODS; i++) {
		if (goods[i].stock - goods[i].sale <= 2) {
			printf("상품 ID %d: 상품명 : %s, 재고부족(%d)\n", i + 1, goods[i].name, goods[i].stock - goods[i].sale);
		}
	}
}