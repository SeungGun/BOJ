#include <stdio.h>
int N;
char str[1000];
char temp[1000];
int len;
void backtracking(int i, int *a) {
	if (len == i) {
		temp[i] = NULL;
		printf("%s", temp);
		return;
	}
	for (int j = 0; j < 26; ++j) {
		if (a[j]) {
			temp[i] = j + 'a';
			--a[j];
			backtracking(i + 1, a);
			++a[j];
		}
	}
}
int main() {
	scanf("%d", &N);
	while (N--) {
		int alp[26] = { 0 };
		int i;
		for (i = 0; str[i]; ++i) {
			++alp[str[i] - 'a'];
		}
		len = i;
		backtracking(0, alp);
		i = 0;
	}
}