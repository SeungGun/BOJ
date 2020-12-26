#include <stdio.h>
int N, S;
int arr[21];
int count = 0;
void backtracking(int i,int sum) {
	if (i == N) {
		if (sum == S) {
			count++;
		}
		return;
	}
	backtracking(i + 1, sum + arr[i]);
	backtracking(i + 1, sum);
}
int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	backtracking(0,0);
	printf("%d", S == 0 ? count-1 : count);
}