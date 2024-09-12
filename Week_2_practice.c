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

	printf("��ǰ ����(����) �Է�(1~100����) : ");
	scanf_s("%d", &quantity);

	printf("��ǰ �� �԰���� �Է� : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &stock[i]);
		totalStock += stock[i];
	}

	printf("��ǰ �� �Ǹż��� �Է� : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &sale[i]);
		totalSale += sale[i];

		if (sale[minSale] > sale[i]) minSale = i;
		if (sale[maxSale] < sale[i]) maxSale = i;
	}

	printf("\n������ : ");
	for (int i = 0; i < quantity; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

	double saleRatio= ((double)totalSale / totalStock) * 100;
	printf("\n�� �Ǹŷ� : %d (�Ǹ���: %.2f%%)\n", totalSale, saleRatio);

	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", maxSale + 1, sale[maxSale]);
	printf("���� ���� �Ǹŵ� ��ǰ: ID %d, �Ǹŷ� %d\n", minSale + 1, sale[minSale]);

	for (int i = 0; i < quantity; i++) {
		if (stock[i] - sale[i] <= 2) {
			printf("��ǰ ID %d: ������(%d)\n", i + 1, stock[i] - sale[i]);
		}
	}
}