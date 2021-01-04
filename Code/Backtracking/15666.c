#include <stdio.h>
#include <stdlib.h>
int N, M;
int arr[9];
int exi[10001];
int idx;
int res[9];
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
		if (i == 0) {
			res[i] = arr[j];
			backtracking(i + 1);
		}
		else {
			if (res[i - 1] <= arr[j]) {
				res[i] = arr[j];
				backtracking(i + 1);
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (!exi[tmp]) {
			exi[tmp] = 1;
			arr[idx++] = tmp;
		}
	}
	qsort(arr, idx, sizeof(int), com);
	backtracking(0);
	
}