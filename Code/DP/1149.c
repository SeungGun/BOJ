#include <stdio.h>
#define min(x,y) (((x) > (y)) ? (y) : (x))
int dp[1001][3];
int N;
int main() {
	int rgb[1001][3];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	}
	dp[0][0] = rgb[0][0];
	dp[0][1] = rgb[0][1];
	dp[0][2] = rgb[0][2];
	for (int i = 1; i < N; i++) {
		dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	int mins = dp[N - 1][0];
	for (int i = 1; i < 3; i++) {
		if (mins > dp[N - 1][i])
			mins = dp[N - 1][i];
	}
	printf("%d", mins);
}