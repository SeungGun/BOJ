#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char S[1002];
char set[1002][1002];
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL)i++;
	return i;
}
int com(const char *a, const char *b) {
	return strcmp(a, b);
}
int main() {
	scanf("%s", S);
	int len = getLength(S);
	for (int i = 0; i < len; i++) {
		strncpy(set[i], S + i, len - i);
	}
	qsort(set, len, sizeof(set[0]), com);
	for (int i = 0; i < len; i++) {
		printf("%s\n", set[i]);
	}
}