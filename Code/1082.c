#include <stdio.h>
char num[52] ="";
int N, money;
int price[10];
int getLength() {
	int i = 0;
	while (num[i] != NULL) i++;
	return i;
}
void concat(int count, int n) {
	int len = getLength();
	for (int i = 0; i < count; i++) {
		num[len + i] = n + 48;
		num[len + i + 1] = NULL;
	}
}
int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &price[i]);
	}
	scanf("%d", &money);

	int min = 100;
	int min_idx = 0;
	for (int i = 0; i < N; i++) {
		if (min >= price[i]) {
			min = price[i];
			min_idx = i;
		}
	}

	int z = money / min;
	concat(z, min_idx);
	money -= z * min;

	int len = getLength();
	int start = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < N; j++) {
			if (money >= price[N - 1 - j] - min) {
				money += min - price[N - 1 - j];
				num[i] = N - j - 1 + 48;
				break;
			}
		}
		if (num[start] == '0') {
			start++;
			money += min;
		}
	}
	if (start == len) {
		printf("0");
		return 0;
	}
	for (int i = start; i < len; i++) {
		printf("%c", num[i]);
	}
}