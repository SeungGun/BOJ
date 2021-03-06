#include <stdio.h>
int memo[45][45];
char str1[45];
char str2[45];
char s1[45] = " ";
char s2[45] = " ";
char result[45];
int getLength(char *a) {
	int i = 0;
	while (a[i] != NULL) i++;
	return i;
}
void concat(char *des, char *so) {
	int des_length = getLength(des);
	int i = 0;
	while (so[i] != NULL) {
		des[des_length++] = so[i++];
	}
	des[des_length] = NULL;
}
int main() {
	int index = 0;
	scanf("%s", str1); scanf("%s", str2);
	concat(s1, str1); concat(s2, str2);
	int s1_l = getLength(s1); int s2_l = getLength(s2);

	for (int i = 0; i < s1_l; i++) {
		for (int j = 0; j < s2_l; j++) {
			if (!i || !j)
				continue;
			if (s1[i] == s2[j]) {
				memo[i][j] = memo[i - 1][j - 1] + 1;
			}
			else {
				memo[i][j] = memo[i - 1][j] > memo[i][j - 1] ? memo[i - 1][j] : memo[i][j - 1];
			}
		}
	}
	if (memo[s1_l - 1][s2_l - 1] == 0)
		return 0;
	int i = s1_l - 1;
	int j = s2_l - 1;

	while (memo[i][j] != 0) {
		if (memo[i][j] == memo[i - 1][j]) {
			i--;
		}
		else if (memo[i][j] == memo[i][j - 1]) {
			j--;
		}
		else {
			result[index++] = s1[i];
			i--;
			j--;
		}

	}
	for (i = index - 1; i >= 0; i--) {
		printf("%c", result[i]);
	}

}