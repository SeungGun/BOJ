#include <stdio.h>
int board[11][11];
int N;
int max[2] = { -1, -1 };
int ltor[20];
int rtol[20];
void backtracking(int row, int col,int count, int color) {
	if (col >= N) {
		row++;
		col = col % 2 ? 0 : 1;
		}
	if(row >= N){
		if (max[color] < count)
			max[color] = count;
		return;
	}
	if (board[row][col] == 1 && !ltor[col - row + N -1] && !rtol[col + row]) {
		ltor[col - row + N - 1] = 1;
		rtol[col + row] = 1;
		backtracking(row,col+2,count + 1,color);
		ltor[col - row + N - 1] = 0;
		rtol[col + row] = 0;
	}
	backtracking(row, col + 2, count, color);
}
int main() {
	scanf("%d", &N);
	//�Ϲ� Backtracking DFS�� ����ϸ� ū �ð����⵵ �߻�
	//�⺻ ü������ �̿� -> üũ���� -> black & whiteĭ�� �и� 
	// �밢�� üũ�� �밢���� �ϳ��� �������� �ϰ�(left -> right : | col - row | , right -> left : col + row) 
	// �迭�� �ε����� �� �밢���� ���ϰ�

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	backtracking(0, 0,0,0);
	backtracking(0, 1, 0, 1);
	printf("%d", max[0] + max[1]);
}