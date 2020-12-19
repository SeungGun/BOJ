#include <stdio.h>
#include <stdlib.h>
typedef struct user {
	int age;
	char name[102];
	int index;
}User;
int com(User *a, User *b) {
	if (a->age > b->age) {
		return 1;
	}
	else if (a->age < b->age) {
		return -1;
	}
	else {
		if (a->index > b->index) {
			return 1;
		}
		else {
			return -1;
		}
	}
}
int main() {
	int N;
	User user[100000];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %s", &user[i].age, user[i].name);
		user[i].index = i;
	}
	qsort(user, N, sizeof(user[0]), com);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", user[i].age, user[i].name);
	}
}