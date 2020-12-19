#include <stdio.h>
#include <string.h>
int stack[10000];
int top = -1;
void push(int num) {
	stack[++top] = num;
}
int pop() {
	if (top != -1)
		return stack[top--];
	else
		return -1;
}
int main() {
	int N;
	char num[8];
	char query[15];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%[^\n]s", query);
		if (!strcmp(query, "top")) {
			top == -1 ? printf("-1\n"): printf("%d\n", stack[top]);
		}
		else if (!strcmp(query, "size")) {
			printf("%d\n", top + 1);
		}
		else if (!strcmp(query, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(query, "empty")) {
			top == -1 ? printf("1\n") : printf("0\n");
		}
		else {
			int i = 5;
			int index = 0;
			int nums = 0;
			while (query[i] != NULL) {
				num[index++] = query[i++] - '0';
			}
			for (int j = 0; j <index; j++) {
				if(j == 0)
					nums += num[j];
				else {
					nums *= 10;
					nums += num[j];
				}
			}
			push(nums);
		}
	}
}