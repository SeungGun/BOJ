#include <stdio.h>
#define MAX_LEVEL 987654321
#define MAX_INDEX 32
typedef struct Point {
	int row;
	int col;
}Pt;
Pt set[1000];
char board[MAX_INDEX][MAX_INDEX];
int visited[MAX_INDEX][MAX_INDEX];
int N, M;
int dot_count = 0;
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
int min = MAX_LEVEL;
int isInner(int cur_row, int cur_col) {
	return cur_row >= 0 && cur_col >= 0 && cur_row < N && cur_col < M;
}
void backtracking(int row, int col, int dir, int cnt, int level) {
	if (cnt == dot_count) {
		if (min > level)
			min = level;
		return;
	}
	int next_col = col + dc[dir];
	int next_row = row + dr[dir];

	if (isInner(next_row, next_col) && !visited[next_row][next_col] && board[next_row][next_col] != '*') {
		visited[next_row][next_col] = 1;
		backtracking(next_row, next_col, dir, cnt + 1, level);
		visited[next_row][next_col] = 0;
	}
	else {
		for (int d = 0; d < 4; d++) {
			if (d != dir) {
				next_col = col + dc[d];
				next_row = row + dr[d];
				if (isInner(next_row, next_col) && !visited[next_row][next_col] && board[next_row][next_col] != '*') {
					visited[next_row][next_col] = 1;
					backtracking(next_row, next_col, d, cnt + 1, level+1);
					visited[next_row][next_col] = 0;
				}
			}
		}
	}
}
int main() {
	int T = 1;
	while (scanf("%d %d", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			getchar();
			for (int j = 0; j < M; j++) {
				scanf("%c", &board[i][j]);
				visited[i][j] = 0;
				if (board[i][j] == '.') {
					set[dot_count].row = i;
					set[dot_count].col = j;
					dot_count++;
				}
			}
		}
		if (dot_count == 1) {
			printf("Case %d: 0\n", T);
			T++;
			dot_count = 0;
			continue;
		}
		for (int i = 0; i < dot_count; i++) {
			for (int dir = 0; dir < 4; dir++) {
				visited[set[i].row][set[i].col] = 1;
				backtracking(set[i].row, set[i].col, dir, 1, 1);
				visited[set[i].row][set[i].col] = 0;
			}
		}
		min == MAX_LEVEL ? printf("Case %d: -1\n",T) : printf("Case %d: %d\n",T,min);
		T++;
		dot_count = 0;
		min = MAX_LEVEL;
	}
}