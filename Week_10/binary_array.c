#include <stdio.h>

int main() {
	int array[1000];
	FILE* fp;
	int i = 0;

	//for (int i = 0; i < 100; i++) array[i] = i;
	//
	//fp = fopen("array.bin", "wb");
	//if (fp == NULL) return -1;
	//
	//fwrite(array, sizeof(char), 100, fp);


	//fp = fopen("array.bin", "rb");
	//if (fp == NULL) return -1;
	//
	//while (fread(&array[i++], sizeof(int), 100, fp));
	//
	//i--;
	//for (int j = 0; j < 100; j++) printf("%d ", array[j]);

	fp = fopen("array.bin", "rb");
	if (fp == NULL) return -1;

	fread(array, sizeof(int), 100, fp);
	
	for (int i = 0; i < 100; i++) printf("%d ", array[i]);
	
	fclose(fp);
	
	return 0;
}