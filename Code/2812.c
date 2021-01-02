#include <stdio.h>
int arr[5000];
int stack[5000];
int top = -1;
void push(int x) {
	stack[++top] = x;
}
int pop() {
	return stack[top--];
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int cnt = K;
	for (int i = 0; i < N; i++) {
		scanf("%1d", &arr[i]);
	}
	for (int i = 0; i < N; i++) {
		while (cnt > 0 && top > -1 && stack[top] < arr[i]) { // ���� ���� ������ top���� ũ�� �� �� �����ϰ�(���� �� ����) ���� ���� ���ÿ� push
															// �׿� ���ÿ� ���ŵ� ī��Ʈ�� �� 
															//stack[top] < arr[i]  -> �� �κ��� �׸��� ���̽� 
			pop(); // ����
			cnt--; // K��ŭ �����ؾ��ϹǷ� ī��Ʈ ��
		}
		push(arr[i]); // �׸��� ���� push
	}
	if (cnt != 0) { // N�� ��ŭ �ݺ��ߴµ��� �ұ��ϰ� K�� ���ŵ��� �ʾҴٸ� 
		for (int i = 0; i <= top-cnt; i++) { // top���� ���� ���� ī��Ʈ������ ���� ���̹Ƿ� ���� 
			printf("%d", stack[i]);
		}
	}
	else {
		for (int i = 0; i <= top; i++) {
			printf("%d", stack[i]);
		}
	}
}