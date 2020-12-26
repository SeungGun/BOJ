#include <stdio.h>
int N;
int count = 0 ;
int rows[16];
int isOverlap(int row) {
	for (int i = 0; i < row; i++) {
		int sign = 0;
		if (rows[row] - rows[i] < 0)
			sign = -1;
		else
			sign = 1;
		if(rows[i] == rows[row] || row - i == sign * (rows[row] - rows[i])){
			return 1;
		}
	}
	return 0;
}
void queen(int row) {
	if (row == N) {
		count++;
		return;
	}
	for (int col = 0; col < N; col++) {
		rows[row] = col;
		if (!isOverlap(row)) {
			queen(row + 1);
		}
	}

}
int main() {
	scanf("%d", &N);
	queen(0);
	printf("%d", count);
}