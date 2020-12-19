#include <stdio.h>
int N, M;
int list[9];
int visited[9];
void backtracking(int i) {
	if (M == i) {
		for (int j = 0; j < M; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= N; j++) {
		if (!visited[j]) {
			visited[j] = 1;
			list[i] = j;
			backtracking(i + 1);
			visited[j] = 0;

		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	backtracking(0);
}