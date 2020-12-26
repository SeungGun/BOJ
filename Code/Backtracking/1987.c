#include <stdio.h>
int R, C;
char board[21][21];
int visited[26];
int count = 0;
int max = -1;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void backtracking(int row, int col, int count) {
	if (row < 0 || row == R || col < 0 || col == C) {
		return;
	}
	if (max < count)
		max = count; 

	for (int i = 0; i < 4; i++) {
		if (!visited[board[row][col] - 'A']) {
			visited[board[row][col] - 'A'] = 1;
			backtracking(row + dx[i], col + dy[i], count + 1);
			visited[board[row][col] - 'A'] = 0;
		}
	}
	
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		getchar();
		for (int j = 0; j < C; j++) {
			scanf("%c", &board[i][j]);
		}
	}
	backtracking(0, 0,0);
	printf("%d", max);
}