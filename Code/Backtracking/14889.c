#include <stdio.h>
int N;
int ay[21][21];
int visited[21];
int min = 1000000000;
int abs(int x) {
	return x < 0 ? -1 * x : x;
}
void backtracking(int c, int i) {
	if (i == N / 2) {
		int start = 0;
		int link = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (visited[j] && visited[k])
					start += ay[j][k];
				else if (!visited[j] && !visited[k])
					link += ay[j][k];
			}
		}
		if (min > abs(start - link))
			min = abs(start - link);
		return;
	}
	for (int j = c + 1; j < N; j++) {
		visited[j] = 1;
		backtracking(j, i + 1);
		visited[j] = 0;
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &ay[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		backtracking(i, 1);
		visited[i] = 0;
	}
	printf("%d", min);
}