#include <stdio.h>
#include <stdlib.h>
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL) i++;
	return i;
}
int* lps(char *pattern) {
	int len = getLength(pattern);
	int *lp = (int*)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++) lp[i] = 0;
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = lp[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			lp[i] = ++j;
		}
	}
	return lp;
}
int KMP(char *str, char * pattern) {
	int len = getLength(str);
	int patt_len = getLength(pattern);
	int *pi = lps(pattern);
	int j = 0;
	for (int i = 0; i < len; i++) {
		while (j > 0 && str[i] != pattern[j]) {
			j = pi[j - 1];
		}
		if (str[i] == pattern[j]) {
			if (j == patt_len - 1) {
				return 1;
			}
			else {
				j++;
			}
		}
	}
	return 0;
}
int main() {
	char str[1000];
	char sub[1000];
	scanf("%s", str);
	scanf("%s", sub);
	if (KMP(str, sub))
		printf("1");
	else
		printf("0");
}