#include <stdio.h>
#include <stdlib.h>

int main() {
	int quantity;
	int stock[100];
	int sale[100];
	int id;

	printf("��ǰ ����(����) �Է�(1~100����) : ");
	scanf_s("%d", &quantity);

	printf("��ǰ �� �԰���� �Է� : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &stock[i]);
	}

	printf("��ǰ �� �Ǹż��� �Է� : ");
	for (int i = 0; i < quantity; i++) {
		scanf_s("%d", &sale[i]);
	}

	printf("ID�Է� : ");
	scanf_s("%d",&id);
	printf("%d\n", stock[id - 1] - sale[id - 1]);


	for (int i = 0; i < quantity; i++) {
		printf("%d ", stock[i] - sale[i]);
	}

}