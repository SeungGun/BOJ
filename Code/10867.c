#include <stdio.h>
#include <stdlib.h>
int arr[10000];
int visit[2001];
int com(int *a, int*b) {
	if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}
int main() {
	int N;
	int idx = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (!visit[tmp + 1000]) {
			arr[idx++] = tmp;
			visit[tmp + 1000] = 1;
		}
	}
	qsort(arr, idx, sizeof(int), com);
	for (int i = 0; i < idx; i++) {
		printf("%d ", arr[i]);
	}
}