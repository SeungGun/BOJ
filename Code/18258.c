#include <stdio.h>
#include <string.h>
int queue[2000001];
int front = 0;
int rear = -1;
void push(int x) {
	queue[++rear] = x;
}
void pop() {
	if (rear - front + 1 == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n",queue[front++]);
	}
}
void empty() {
	if (rear - front + 1 == 0)
		printf("1\n");
	else
		printf("0\n");
}
int main() {
	int N;
	char query[6];
	int x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%s", query);
		if (!strcmp(query, "pop")) {
			pop();
		}
		else if (!strcmp(query, "size")) {
			printf("%d\n", rear - front + 1);
		}
		else if (!strcmp(query, "empty")) {
			empty();
		}
		else if (!strcmp(query, "front")) {
			rear - front + 1 == 0 ? printf("-1\n") : printf("%d\n", queue[front]);
		}
		else if (!strcmp(query, "back")) {
			rear - front +1 == 0 ? printf("-1\n") :printf("%d\n", queue[rear]);
		}
		else {
			scanf("%d", &x);
			push(x);
		}
	}
}