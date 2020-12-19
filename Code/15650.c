#include <stdio.h>
int N, M;
int list[9];
void backtracking(int i) {
	if (M == i) {
		for (int i = 0; i < M; i++) {
			printf("%d ", list[i]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= N; j++) {
		if (i == 0) {
			list[i] = j;
			backtracking(i + 1);
		}
		else {
			if (list[i - 1] < j) {
				list[i] = j;
				backtracking(i + 1);
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);
}