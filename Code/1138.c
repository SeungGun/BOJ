#include <stdio.h>
int main() {
	int N;
	int left[11];
	int isOccupied[11] = { 0 };
	int line[11];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &left[i]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!left[i]&& !isOccupied[j]) {
				line[j+1] = i + 1;
				isOccupied[j] = 1;
				break;
			}
			else if (!isOccupied[j]) {
				left[i]--;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", line[i]);
	}
}