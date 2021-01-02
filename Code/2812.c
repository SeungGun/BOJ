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
		while (cnt > 0 && top > -1 && stack[top] < arr[i]) { // 현재 값이 스택의 top보다 크면 그 값 제거하고(작을 때 까지) 현재 값을 스택에 push
															// 그와 동시에 제거된 카운트를 셈 
															//stack[top] < arr[i]  -> 이 부분이 그리디 초이스 
			pop(); // 제거
			cnt--; // K만큼 제거해야하므로 카운트 셈
		}
		push(arr[i]); // 그리고 나서 push
	}
	if (cnt != 0) { // N번 만큼 반복했는데도 불구하고 K번 제거되지 않았다면 
		for (int i = 0; i <= top-cnt; i++) { // top에서 부터 남은 카운트까지는 작은 값이므로 무시 
			printf("%d", stack[i]);
		}
	}
	else {
		for (int i = 0; i <= top; i++) {
			printf("%d", stack[i]);
		}
	}
}