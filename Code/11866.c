#include <stdio.h>
int cir[1002];
int visited[1002];
int permu[1002];
int visit_count;
int main() {
	int N, K;
	int cur_idx = 0;
	scanf("%d %d", &N, &K);
	int j = 0;
	for (int i = 1; i <= N; i++) {
		cir[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		int iter = 0;

		while(iter != K){
			j++;
			if (j > N)
				j = 1;
			if (!visited[j]) {
				iter++;
			}
		}
		//printf("j : %d\n", j);
		permu[i] = cir[j];
		visited[j] = 1;
	}
	printf("<");
	for (int i = 1; i <= N; i++) {
		if (i == N)
			printf("%d", permu[i]);
		else
			printf("%d, ", permu[i]);
	}
	printf(">");
}