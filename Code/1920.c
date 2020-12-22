#include <stdio.h>
#include <stdlib.h>
int com(int *a, int*b) {
	if (*a > *b)
		return 1;
	else
		return -1;
}
int A[10000];
int main() {
	int N,M;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), com);
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int tmp;
		int flag = 0;
		scanf("%d", &tmp);
		int left = 0;
		int right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] > tmp) {
				right = mid - 1;
			}
			else if (A[mid] < tmp) {
				left = mid + 1;
			}
			else {
				flag = 1;
				break;
			}
		}
		flag == 1 ? printf("1\n") : printf("0\n");
	}

}