#include <stdio.h>
int R, C;
char board[21][21];
int visited[26];
int count = 0;
int max = -1;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
void backtracking(int row, int col, int count) {

	if (max < count)
		max = count; 

	for (int i = 0; i < 4; i++) {
		int nxt_row = row + dx[i];
		int nxt_col = col + dy[i];
		if (nxt_row >= 0 && nxt_row < R && nxt_col >= 0 && nxt_col < C) {
			if (!visited[board[row][col] - 'A']) {
				visited[board[row][col] - 'A'] = 1;
				backtracking(nxt_row, nxt_col, count + 1);
				visited[board[row][col] - 'A'] = 0;
			}
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