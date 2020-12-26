#include <stdio.h>
int N, M;
int list[9];
void backtracking(int i) {
	if (M == i) {
		for (int j = 0; j < M; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= N; j++) {
		list[i] = j;
		backtracking(i + 1);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);
}