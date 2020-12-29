#include <stdio.h>
#include <stdlib.h>
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL) i++;
	return i;
}
int* getLPS(char *str,int len) {
	int *lps = (int*)malloc(sizeof(int) * len);
	int j = 0;
	int i;
	for (i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j]) {
			j = lps[j - 1];
		}
		if (str[i] == str[j]) {
			lps[i] = ++j;
		}
	}
	return lps;
}
int main() {
	char str[1000002];
	int *lps;
	int len;
	while (1) {
		scanf("%s", str);
		getchar();
		if (getLength(str) == 1 && str[0] == '.')
			break;
		len = getLength(str);
		lps = getLPS(str,len);
		if (!lps[len - 1] || lps[len - 1] % (len - lps[len - 1]))
			printf("1\n");
		else
			printf("%d\n", len / (len - lps[len - 1]));
	}
}