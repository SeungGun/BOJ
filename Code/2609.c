#include <stdio.h>
int GCD(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return GCD(b, a % b);
	}
}
int main() {
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	int result = GCD(n1, n2);
	printf("%d\n%d", result, n1 * n2 / result);
}