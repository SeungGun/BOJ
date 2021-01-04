#include <stdio.h>
#include <stdlib.h>
int N, M;
int arr[8];
int res[8];
int idx;
int visit[10001];
int com(int *a, int *b) {
	if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}
void backtracking(int i) {
	if (i == M) {
		for (int j = 0; j < M; j++) {
			printf("%d ", res[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 0; j < idx; j++) {
		res[i] = arr[j];
		backtracking(i + 1);
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (!visit[tmp]) {
			arr[idx++] = tmp;
			visit[tmp] = 1;
		}
	}
	qsort(arr, idx, sizeof(int), com);
	backtracking(0);

}