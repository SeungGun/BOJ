#include <stdio.h>
#include <stdio.h>
typedef struct person {
	int weight;
	int height;
}Ps;
int main() {
	int N;
	Ps person[51];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d %d", &person[i].weight, &person[i].height);
	for (int i = 0; i < N; i++) {
		int k = 0;
		for (int j = 0; j < N; j++) {
			if (person[i].height < person[j].height && person[i].weight < person[j].weight) 
				k++;
		}
		printf("%d ", k+1);
	}
}
