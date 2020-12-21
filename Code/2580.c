#include <stdio.h>
typedef struct point {
	int row;
	int col;
}Pt;
int sudoku[9][9];
int output = 0;
int empty_count = 0;
Pt empty[82];
int isOverlap(int row, int col) {
	int ro = row / 3;
	int co = col / 3;
	for (int r = 0; r < 9; r++) {
		if (sudoku[row][col] == sudoku[r][col] && r != row) {
			return 1;
		}
	}
	for (int c = 0; c < 9; c++) {
		if (sudoku[row][col] == sudoku[row][c] && c != col) {
			return 1;
		}
	}
	for (int r = ro * 3; r < (ro * 3) + 3; r++) {
		for (int c = co * 3; c < (co * 3) + 3; c++) {
			if (sudoku[row][col] == sudoku[r][c] && r != row && c != col) {
				return 1;
			}
		}
	}
	return 0;
}
void backtracking(int em) {
	if (em == empty_count && !output) {
		output = 1;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {	
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= 9; i++) {
		sudoku[empty[em].row][empty[em].col] = i;
		if (!isOverlap(empty[em].row, empty[em].col)) {
			backtracking(em + 1);
		}
		sudoku[empty[em].row][empty[em].col] = 0;
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &sudoku[i][j]);
			if (!sudoku[i][j]) {
				empty[empty_count].row = i;
				empty[empty_count++].col = j;
			}
		}
	}
	backtracking(0);
}