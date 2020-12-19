#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL)
		i++;
	return i;
}
int com(char *a, char *b) {
	if (getLength(a) > getLength(b)) {
		return 1;
	}
	else if (getLength(a) < getLength(b)) {
		return -1;
	}
	else {
		return strcmp(a, b);
	}
}
int main() {
	int N;
	char str[20000][51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", str[i]);
	}
	qsort(str, N, sizeof(str[0]), com);

	for (int i = 0; i < N; i++) {
		if (!strcmp(str[i], str[i + 1])) {
			continue;
		}
		else {
			printf("%s\n", str[i]);
		}
	}
}