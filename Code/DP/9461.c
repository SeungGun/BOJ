#include <stdio.h>
int P[101];
int main() {
	int T;
	scanf("%d", &T);
	P[0] = 1;
	P[1] = 1;
	P[2] = 1;
	P[3] = 2;
	P[4] = 2;
	for (int i = 0; i < T; i++) {
		int tmp;
		scanf("%d", &tmp);
		for (int i = 5; i < tmp; i++) {
			P[i] = P[i - 1] + P[i - 5];
		}
		printf("%d\n", P[tmp-1]);
	}
}