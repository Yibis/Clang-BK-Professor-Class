#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void outFile(Goods* goods, char ch[], int id, const char* output_file);
void saveFile(Goods* goods);
void loadFile(Goods* goods);

int main() {
	Goods goods[100] = { 0 };
	int num;

	for (int i = 0; i < GOODS; i++) {
		goods[i].id = 0;
	}

	do {
		printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황, 5. 상품정보저장, 6. 상품정보가져오기, 7. 종료)\n");
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
			saveFile(goods);
			break;
		case 6:
			loadFile(goods);
			break;
		case 7:
			printf("프로그램을 종료합니다.\n");
			break;
		default:
			printf("다시 입력해주세요.\n");
			break;
		}
		printf("\n");
	} while (num != 7);
}

void stockGoods(Goods* goods) {
	int id, temp;
	int newID = 0;

	printf("상품ID : ");
	scanf_s("%d", &id);
	if (id <= GOODS && id >= 1) {
		if (goods[id - 1].id == 0) {
			printf("상품명 : ");
			getchar();
			gets(goods[id - 1].name);
			goods[id - 1].id = id;
			newID = 1;
		}
		printf("입고량 : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock == 0) goods[id - 1].stock = temp;
		else goods[id - 1].stock += temp;
		if (newID == 1) {
			printf("판매가격 : ");
			scanf_s("%d", &goods[id - 1].price);
		}
	}
	else printf("잘못 된 ID입니다");
}

void saleGoods(Goods* goods) {
	int id, temp;

	printf("상품ID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("존재하지 않는 ID입니다.");
	else {
		printf("판매량 : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock < temp) printf("남은 재고 수량보다 많은 판매량입니다.");
		else goods[id - 1].sale += temp;
	}
}

void indStatusGoods(Goods* goods) {
	int id, temp;
	char output_file[100], ch[100000];

	printf("상품ID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("존재하지 않는 ID입니다.");
	else {
		sprintf(output_file, "%d번.txt", id);
		sprintf(ch, "상품명 : %s\n판매가격 : %d\n재고수량 : %d\n총 판매가 : %d\n", goods[id - 1].name, goods[id - 1].price, goods[id - 1].stock - goods[id - 1].sale, goods[id - 1].sale * goods[id - 1].price);
		outFile(goods, ch, id, output_file);
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
		printf("ID %d : %d ", i + 1, goods[i].stock - goods[i].sale);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n총 판매량 : %d (판매율: %.2f%%)\n", totalSale, saleRatio);

	temp = 0;
	for (int i = 0; i < GOODS; i++) temp += goods[i].price * goods[i].sale;
	printf("총 판매가 : %d원\n", temp);

	printf("가장 많이 판매된 상품: ID %d, 상품명: %s, 판매량: %d\n", maxSale + 1, goods[maxSale].name, goods[maxSale].sale);
	printf("가장 적게 판매된 상품: ID %d, 상품명: %s, 판매량: %d\n", minSale + 1, goods[minSale].name, goods[minSale].sale);

	for (int i = 0; i < GOODS; i++) {
		if (goods[i].stock - goods[i].sale <= 2) {
			printf("상품 ID %d: 상품명 : %s, 재고부족(%d)\n", i + 1, goods[i].name, goods[i].stock - goods[i].sale);
		}
	}
}

void outFile(Goods* goods, char ch[], int id, const char* output_file) {
	FILE* out_fp;
	int i = 0;

	out_fp = fopen(output_file, "w");

	while (ch[i] != '\0') {
		fputc(ch[i], out_fp);
		i++;
	}

	fclose(out_fp);
}

void saveFile(Goods* goods) {
	FILE* fp;
	fp = fopen("struct.bin", "wb");

	if (fp == NULL) {
		printf("파일 열기 실패");
		return;
	}

	fwrite(goods, sizeof(Goods), GOODS, fp);

	fclose(fp);
	printf("파일 저장 완료\n");
}

void loadFile(Goods* goods) {
	FILE* fp;
	fp = fopen("struct.bin", "rb");

	if (fp == NULL) {
		printf("저장된 파일이 없습니다.\n");
		return;
	}

	fread(goods, sizeof(Goods), GOODS, fp);

	fclose(fp);
	printf("파일 불러오기 완료\n");
}