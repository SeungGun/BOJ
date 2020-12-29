#include <stdio.h>
int main() {
	int T, n;
	int a[1000] = { 0 };
	int p[1000] = { 0 };
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &n);
		int min = 100001;
		int idx = 0;
		int part1;
		int part2;
		for (int j = 2; j <= n; j++) {
			for (int k = 2; j*k <= n; k++) {
				a[j*k] = 1;
			}
		}
		for (int j = 2; j <= n; j++) {
			if (!a[j]) {
				p[idx++] = j;
				printf("%d ", j);
			}
		}
		printf("\n");
		for (int j = 0; j < idx; j++) {
			for (int k = 0; k < idx; k++) {
				if (p[j] + p[k] == n && p[j] - p[k] >= 0) {
					if (min > p[j] - p[k]) {
						min = p[j] - p[k];
						part1 = p[k];
						part2 = p[j];
					}
					//printf("%d  + %d = %d\n", p[j], p[k], n);
				}
			}
		}
		printf("%d %d\n", part1, part2);
	}

}