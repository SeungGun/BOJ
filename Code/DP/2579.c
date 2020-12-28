#include <stdio.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))
int stairs[301];
int dp[301];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &stairs[i]);
	}
	int sum = 0;

	
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			dp[i] = stairs[i];
		}
		else if (i == 1) {
			dp[i] = stairs[i-1] + stairs[i];
		}
		else if(i == 2){
			dp[i] = stairs[i] + max(stairs[i - 1], stairs[i - 2]); 
		}
		else {
			dp[i] = stairs[i] + max(dp[i - 3] + stairs[i - 1], dp[i - 2]);
		}
	}
	printf("%d", dp[N-1]);
}