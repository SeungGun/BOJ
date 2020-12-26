#include <stdio.h>
int N;
int list[12];
int oper[4];
int min = 1000000000;
int max = -1000000000;
int index = 1;
int result = 0;
void backtracking(int i) {
	if (i == N-1) {
		if (min > result) min = result;
		if (max < result) max = result;
		return;
	}
	for (int j = 0; j < 4; j++) {
		if (oper[j] != 0) {
			if (j == 0) {
				int prev = result;
				int tmp = list[index++];
				result += tmp;
				oper[j]--;
				backtracking(i + 1);
				oper[j]++;
				index--;
				result = prev;
			}
			else if (j == 1) {
				int prev = result;
				int tmp = list[index++];
				result -= tmp;
				oper[j]--;
				backtracking(i + 1);
				oper[j]++;
				index--;
				result = prev;
			}
			else if(j == 2) {
				int prev = result;
				int tmp = list[index++];
				result *= tmp;
				oper[j]--;
				backtracking(i + 1);
				oper[j]++;
				index--;
				result = prev;
			}
			else if (j == 3) {
				int prev = result;
				int tmp = list[index++];
				result /= tmp;
				oper[j]--;
				backtracking(i + 1);
				oper[j]++;
				index--;
				result = prev;
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &list[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	result = list[0];
	backtracking(0);
	printf("%d\n%d", max, min);
}