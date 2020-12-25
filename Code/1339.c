#include <stdio.h>
#include <stdlib.h>
#define MAX_ALPHABET 26
int tens[9] = { 1,10,100,1000,10000,100000,1000000,10000000, 100000000 };
int N;
int alphabet[MAX_ALPHABET];
char words[11][11];
int sum = 0;
int count = 9;
int com(int *a, int *b) {
	if (*a > *b)
		return -1;
	else
		return 1;
}
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL) i++;
	return i;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", words[i]);
	}
	for (int i = 0; i < N; i++) {
		int j = 0;
		int length = getLength(words[i]);
		while (words[i][j] != NULL) {
			alphabet[words[i][j] - 'A'] += tens[(length - 1) - j];
			j++;
		}
	}
	qsort(alphabet, MAX_ALPHABET, sizeof(int), com);
	for (int i = 0; i < MAX_ALPHABET; i++) {
		if (alphabet[i] > 0) {
			sum += alphabet[i] * count--;
		}
	}
	printf("%d", sum);
}