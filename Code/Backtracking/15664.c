#include <stdio.h>
#include <stdlib.h>
int N, M;
int arr[9];
int res[9];
int visit[9];
int com(int *a, int *b) {
	if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}
void backtracking(int i, int s) {
	if (M == i) {
		for (int j = 0; j < M; j++) {
			printf("%d ", res[j]);
		}
		printf("\n");
		return;
	}
	int prev = -1;
	for (int j = s; j < N; j++) {
		if (!visit[j] && prev != arr[j]) {
			visit[j] = 1;
			res[i] = arr[j];
			prev = arr[j];
			backtracking(i + 1, j);
			visit[j] = 0;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), com);
	backtracking(0,0);
}