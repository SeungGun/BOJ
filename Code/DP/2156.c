#include <stdio.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
int wine[10001];
int dp[10001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &wine[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			dp[i] = wine[i];
		}
		else if (i == 1) {
			dp[i] = wine[i - 1] + wine[i];
		}
		else {
			printf("%d\n", dp[i - 3]);
			// 연속으로 한번 마시는 경우 , 연속으로 두번 마시는 경우 
			dp[i] = max(dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
			// 연속으로 0번 마시는 경우
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	printf("%d", dp[n-1]);

}