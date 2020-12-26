#include <stdio.h>
int memo[1002][1002];
char str1[1003];
char str2[1003];
char s1[1003] = " ";
char s2[1003] = " ";
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
	scanf("%s", str1); scanf("%s", str2);
	concat(s1, str1); concat(s2, str2);
	int s1_l = getLength(s1); int s2_l = getLength(s2);

	for (int i = 0; i <s1_l; i++) {
		for (int j = 0; j < s2_l; j++) {
			if (!i || !j)
				continue;
			if(s1[i] == s2[j]) {
				memo[i][j] = memo[i - 1][j - 1] + 1;
			}
			else {
				memo[i][j] = memo[i - 1][j] > memo[i][j - 1] ? memo[i - 1][j] : memo[i][j - 1];
			}
		}
	}
	printf("%d", memo[s1_l - 1][s2_l - 1]);
}