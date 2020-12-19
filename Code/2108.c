#include <stdio.h>
#include <stdlib.h>
#define RANGE 8001
#define MAX_INDEX 500001
int com(int *a, int *b) {
	if (*a > *b)
		return 1;
	else
		return 0;
}
int main() {
	int N;
	int arr[MAX_INDEX];
	int freq[RANGE] = { 0 };
	int count = 0;
	double sum = 0.0;
	int freq_result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		freq[arr[i] + 4000]++;
		sum += arr[i];
	}
	int max = freq[0];
	for (int i = 1; i < RANGE; i++) {
		if (max < freq[i]) {
			max = freq[i];
		}
	}
	for (int i = 0; i < RANGE; i++) {
		if (max == freq[i])
			count++;
	}
	for (int i = 0; i < RANGE; i++) {
		if (count == 1) {
			if (max == freq[i]) {
				freq_result = i - 4000;
				break;
			}
		}
		else {
			if (max == freq[i]) {
				if (count == 0) {
					freq_result = i - 4000;
					break;
				}
				else
					count = 0;
			}
		}
	}
	qsort(arr, N, sizeof(int), com);

	printf("%.0lf\n", sum / N);
	printf("%d\n", arr[N / 2]);
	printf("%d\n", freq_result);
	printf("%d\n", arr[N - 1] - arr[0]);

}