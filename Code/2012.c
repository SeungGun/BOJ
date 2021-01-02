#include <stdio.h>
#include <stdlib.h>
int arr[500001];
int abs(int x) {
	return x < 0 ? -1 * x : x;
}
int com(const int*a, const int*b) {
	if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}
int main() {
	int N;
	long long complain = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), com);

	for (int i = 0; i < N; i++) {
		complain += abs(arr[i] - (i + 1));
	}
	printf("%lld", complain);
}