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
		printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ��ǰ��Ȳ, 4. ����)\n");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		default:
			printf("�ٽ� �Է����ּ���.\n");
			break;
		}
		printf("\n");
	} while (num != 4);
}


void stockGoods(int* stock) {
	int num, id, temp;

	printf("�԰���� �Է� : ��ü ��ǰ �԰���� �Է� 1, ���� ��ǰ �Է� 2�� ����\n1 2 ���� : ");
	scanf_s("%d", &num);

	if (num == 1) {
		printf("��ǰ �� �԰���� �Է� : ");
		for (int i = 0; i < GOODS; i++) {
			scanf_s("%d", &temp);
			stock[i] += temp;
		}
	} else if (num == 2) {
		printf("��ǰID : ");
		scanf_s("%d", &id);
		if (id <= GOODS || id >= 1) {
			printf("�԰���� �Է� : ");
			scanf_s("%d", &temp);
			stock[id - 1] += temp;
		}
		else {
			printf("�߸��� �Է��Դϴ�.");
		}
	} else {
		printf("�߸��� �Է��Դϴ�.");
	}

}

void saleGoods(int* sale) {
	int num, id, temp;

	printf("�Ǹż��� �Է� : ��ü ��ǰ �Ǹż��� �Է� 1, ���� ��ǰ �Է� 2�� ����\n1 2 ���� : ");
	scanf_s("%d", &num);

	if (num == 1) {
		printf("��ǰ �� �Ǹż��� �Է� : ");
		for (int i = 0; i < GOODS; i++) {
			scanf_s("%d", &temp);
			sale[i] += temp;
		}
	} else if (num == 2) {
		printf("��ǰID : ");
		scanf_s("%d", &id);
		if (id <= GOODS || id >= 1) {
			printf("�Ǹż��� �Է� : ");
			scanf_s("%d", &temp);
			sale[id - 1] += temp;
		} else {
			printf("�߸��� �Է��Դϴ�.");
		}
	} else {
		printf("�߸��� �Է��Դϴ�.");
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

	printf("������ : ");
	for (int i = 0; i < GOODS; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

	double saleRatio = ((double)totalSale / totalStock) * 100;
	printf("\n�� �Ǹŷ� : %d (�Ǹ���: %.2f%%)\n", totalSale, saleRatio);

	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxSale + 1, sale[maxSale]);
	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minSale + 1, sale[minSale]);

	for (int i = 0; i < GOODS; i++) {
		if (stock[i] - sale[i] <= 2) {
			printf("��ǰ ID %d: ������(%d)\n", i + 1, stock[i] - sale[i]);
		}
	}
}