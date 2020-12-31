#include <stdio.h>
typedef struct priority {
	int index;
	int prior;
}Pr;
int pri[111];
Pr queue[1001];
int front = 0;
int rear = -1;
void enqueue(Pr data) {
	queue[++rear] = data;
}
Pr dequeue() {
	return queue[front++];
}
int main() {
	int T, N, M;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int count = 0;
		front = 0;
		rear = -1;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &pri[i]);
			enqueue((Pr){ i,pri[i] });
		}
		while (1) {
			int flag = 0;
			for (int i = front + 1; i <= rear; i++) {
				if (queue[front].prior < queue[i].prior) {
					enqueue(dequeue());
					flag = 1;
					break;
				}
			}
			if (!flag) {
				Pr deq = dequeue();
				count++;
				if (deq.index == M)
					break;
			}
		}
		printf("%d\n", count);
	}
}
