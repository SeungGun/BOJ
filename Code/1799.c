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
	//일반 Backtracking DFS를 사용하면 큰 시간복잡도 발생
	//기본 체스판을 이용 -> 체크무늬 -> black & white칸을 분리 
	// 대각선 체크는 대각선을 하나의 패턴으로 하고(left -> right : | col - row | , right -> left : col + row) 
	// 배열의 인덱스를 각 대각선의 패턴값

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	backtracking(0, 0,0,0);
	backtracking(0, 1, 0, 1);
	printf("%d", max[0] + max[1]);
}