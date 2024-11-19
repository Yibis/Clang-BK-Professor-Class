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
		printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ, 4. ��ü��Ȳ, 5. ��ǰ��������, 6. ��ǰ������������, 7. ����)\n");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�ٽ� �Է����ּ���.\n");
			break;
		}
		printf("\n");
	} while (num != 7);
}

void stockGoods(Goods* goods) {
	int id, temp;
	int newID = 0;

	printf("��ǰID : ");
	scanf_s("%d", &id);
	if (id <= GOODS && id >= 1) {
		if (goods[id - 1].id == 0) {
			printf("��ǰ�� : ");
			getchar();
			gets(goods[id - 1].name);
			goods[id - 1].id = id;
			newID = 1;
		}
		printf("�԰� : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock == 0) goods[id - 1].stock = temp;
		else goods[id - 1].stock += temp;
		if (newID == 1) {
			printf("�ǸŰ��� : ");
			scanf_s("%d", &goods[id - 1].price);
		}
	}
	else printf("�߸� �� ID�Դϴ�");
}

void saleGoods(Goods* goods) {
	int id, temp;

	printf("��ǰID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("�������� �ʴ� ID�Դϴ�.");
	else {
		printf("�Ǹŷ� : ");
		scanf_s("%d", &temp);
		if (goods[id - 1].stock < temp) printf("���� ��� �������� ���� �Ǹŷ��Դϴ�.");
		else goods[id - 1].sale += temp;
	}
}

void indStatusGoods(Goods* goods) {
	int id, temp;
	char output_file[100], ch[100000];

	printf("��ǰID : ");
	scanf_s("%d", &id);
	if (id != goods[id - 1].id) printf("�������� �ʴ� ID�Դϴ�.");
	else {
		sprintf(output_file, "%d��.txt", id);
		sprintf(ch, "��ǰ�� : %s\n�ǸŰ��� : %d\n������ : %d\n�� �ǸŰ� : %d\n", goods[id - 1].name, goods[id - 1].price, goods[id - 1].stock - goods[id - 1].sale, goods[id - 1].sale * goods[id - 1].price);
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

	printf("������ : ");
	for (int i = 0; i < GOODS; i++) {
		printf("ID %d : %d ", i + 1, goods[i].stock - goods[i].sale);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n�� �Ǹŷ� : %d (�Ǹ���: %.2f%%)\n", totalSale, saleRatio);

	temp = 0;
	for (int i = 0; i < GOODS; i++) temp += goods[i].price * goods[i].sale;
	printf("�� �ǸŰ� : %d��\n", temp);

	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, ��ǰ��: %s, �Ǹŷ�: %d\n", maxSale + 1, goods[maxSale].name, goods[maxSale].sale);
	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, ��ǰ��: %s, �Ǹŷ�: %d\n", minSale + 1, goods[minSale].name, goods[minSale].sale);

	for (int i = 0; i < GOODS; i++) {
		if (goods[i].stock - goods[i].sale <= 2) {
			printf("��ǰ ID %d: ��ǰ�� : %s, ������(%d)\n", i + 1, goods[i].name, goods[i].stock - goods[i].sale);
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
		printf("���� ���� ����");
		return;
	}

	fwrite(goods, sizeof(Goods), GOODS, fp);

	fclose(fp);
	printf("���� ���� �Ϸ�\n");
}

void loadFile(Goods* goods) {
	FILE* fp;
	fp = fopen("struct.bin", "rb");

	if (fp == NULL) {
		printf("����� ������ �����ϴ�.\n");
		return;
	}

	fread(goods, sizeof(Goods), GOODS, fp);

	fclose(fp);
	printf("���� �ҷ����� �Ϸ�\n");
}