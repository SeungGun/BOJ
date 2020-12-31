#include <stdio.h>
int queue[1000];
int front = -1;
int rear = -1;
void enqueue(int x) {
	queue[++rear] = x;
}
int dequeue() {
	return queue[++front];
}
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		enqueue(i);
	}
	while (1) {
		dequeue();
		if (rear - front == 1) {
			break;
		}
		enqueue(dequeue());
		if (rear - front == 1) {
			break;
		}
	}
	printf("%d", queue[rear]);
}