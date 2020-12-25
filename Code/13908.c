#include <stdio.h>
int n, m;
int know[10];
int code[8];
int count;
int num_count[10];
void backtracking(int i) {
	if (i == n) {
		for (int j = 0; j < m; j++) {
			if (num_count[know[j]] < 1) {
				return;
			}
		}
		count++;
		return;
	}
	for (int j = 0; j <= 9; j++) {
		num_count[j]++;
		backtracking(i + 1);
		num_count[j]--;
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &know[i]);
	}
	backtracking(0);
	printf("%d", count);
}