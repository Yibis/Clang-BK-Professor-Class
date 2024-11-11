#include<stdio.h>
#define SIZE 100

int main() {
	char input[SIZE];
	FILE* fp = NULL;
	int i = 0;

	if ((fp = fopen("output.bin", "wb")) == NULL) {
		printf("error...");
		return 0;
	}

	while (!feof(fp)) {
		fread(&input[i], sizeof(char), 1, fp);
		i++;
	}
	input[--i] = '\0';

	gets(input);
	//fputs(input, fp);

	fwrite(input, strlen(input), 1, fp);
	fclose(fp);
	
	return 0;
}