#include <stdio.h>
char T[1000];
char P[1000];
int occur[1000];
int lps[1000];
int T_len;
int P_len;
int count = 0;
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL) i++;
	return i;
}
void getLPS() {
	int j = 0;
	for (int i = 1; i < P_len; i++) {
		while (j > 0 && P[i] != P[j]) {
			j = lps[j - 1];
		}
		if (P[i] == P[j]) {
			lps[i] = ++j;
		}
	}
}
int main() {
	scanf("%[^\n]s", T);
	getchar();
	scanf("%[^\n]s", P);
	T_len = getLength(T);
	P_len = getLength(P);
	getLPS();
	int j = 0;
	for (int i = 0; i < T_len; i++) {
		while (j > 0 && T[i] != P[j]) {
			j = lps[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == P_len - 1) {
				occur[count++] = i - P_len + 2;
				j = lps[j];
			}
			else {
				j++;
			}
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d\n", occur[i]);
	}
}