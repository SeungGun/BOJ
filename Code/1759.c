#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int L, C;
char comp[16];
int visited[16];
char enc[16];
char result[230][16];
int cnt = 0;
int com(const void * a, const void *b) {
	return strcmp((char*)a, (char*)b);
}
void backtracking(int i, int vow, int con) {
	if (i == L) {
		if (vow >= 1 && con >= 2) {
			for (int k = 0; k < L; k++) {
				result[cnt][k] = enc[k];
			}
			result[cnt++][L] = NULL;
		}
		return;
	}
	for (int j = 0; j < C; j++) {
		if (!visited[j]) {
			if (comp[j] == 'a' || comp[j] == 'e' || comp[j] == 'i' || comp[j] == 'o' || comp[j] == 'u') {
				if (i != 0) {
					if (enc[i - 1] < comp[j]) {
						visited[j] = 1;
						enc[i] = comp[j];
						backtracking(i + 1, vow + 1, con);
						visited[j] = 0;
					}
				}
				else {
					enc[i] = comp[j];
					visited[j] = 1;
					backtracking(i + 1, vow + 1, con);
					visited[j] = 0;
				}
			}
			else {
				if (i != 0) {
					if (enc[i - 1] < comp[j]) {
						visited[j] = 1;
						enc[i] = comp[j];
						backtracking(i + 1, vow, con+1);
						visited[j] = 0;
					}
				}
				else {
					visited[j] = 1;
					enc[i] = comp[j];
					backtracking(i + 1, vow, con+1);
					visited[j] = 0;
				}
			}
		}
	}
}
int main() {
	scanf("%d %d", &L, &C);
	int idx = 0;
	getchar();
	for (int i = 0; i < C * 2; i++) {
		char tmp = '-';
		scanf("%c", &tmp);
		if (!(i % 2)) {
			comp[idx++] = tmp;
		}
	}
	backtracking(0, 0, 0);
	qsort(result, cnt, sizeof(result[0]), com);
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", result[i]);
	}
}