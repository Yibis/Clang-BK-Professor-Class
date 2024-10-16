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
		printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ����)\n");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�ٽ� �Է����ּ���.\n");
			break;
		}
		printf("\n");
	} while (num != 5);
}


void stockGoods(Goods* goods) {
	int id, temp;

	printf("��ǰID : ");
	scanf_s("%d", &id);
	goods[id - 1].id = id;
	printf("��ǰ�� : ");
	getchar();
	gets_s(goods[id - 1].name, 100);
	printf("�԰� : ");
	scanf_s("%d", &temp);
	goods[id - 1].stock += temp;
	printf("�ǸŰ��� : ");
	scanf_s("%d", &goods[id - 1].price);
}

void saleGoods(Goods* goods) {
	int id, temp;

	printf("��ǰID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("�������� �ʴ� ID�Դϴ�.");
	else {
		printf("�Ǹŷ� : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock < goods[id - 1].sale) printf("���� ��� �������� ���� �Ǹŷ��Դϴ�.");
		else goods[id - 1].sale += temp;
	}
}

void indStatusGoods(Goods* goods) {
	int id, temp;

	printf("��ǰID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("�������� �ʴ� ID�Դϴ�.");
	else {
		printf("��ǰ�� : %s\n", goods[id - 1].name);
		printf("�ǸŰ��� : %d\n", goods[id - 1].price);
		printf("������ : %d\n", goods[id - 1].stock - goods[id - 1].sale);
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

	printf("������ : ");
	for (int i = 0; i < GOODS; i++) {
		printf("ID %d : %d ", i+1, goods[i].stock - goods[i].sale);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n�� �Ǹŷ� : %d (�Ǹ���: %.2f%%)\n", totalSale, saleRatio);
	
	temp = 0;
	for (int i = 0; i < GOODS; i++) temp += goods[i].price * goods[i].sale;
	printf("�� �ǸŰ� : %d��\n", temp);

	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", maxSale + 1, goods[maxSale].name, goods[maxSale].sale);
	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, ��ǰ��: %s, �Ǹŷ� %d\n", minSale + 1, goods[minSale].name, goods[minSale].sale);

	for (int i = 0; i < GOODS; i++) {
		if (goods[i].stock - goods[i].sale <= 2) {
			printf("��ǰ ID %d: ��ǰ�� : %s, ������(%d)\n", i + 1, goods[i].name, goods[i].stock - goods[i].sale);
		}
	}
}