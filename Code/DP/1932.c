#include <stdio.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
int dp[501][501];
int tri[501][501];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			dp[i][j] = tri[i][j]+ max(dp[i - 1][j], dp[i-1][j-1]);
		}
	}
	int max = dp[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (max < dp[n - 1][i]) {
			max = dp[n - 1][i];
		}
	}
	printf("%d", max);
}