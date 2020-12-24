#include <stdio.h>
#include <stdlib.h>
typedef struct time {
	int start;
	int end;
}Time;
Time times[1000];
int N;
int com(Time *a, Time *b) {
	if (a->end > b->end) {
		return 1;
	}
	else if(a->end < b->end){
		return -1;
	}
	else {
		if (a->start > b->start) {
			return 1;
		}
		else {
			return -1;
		}
	}
}
int main() {
	scanf("%d", &N);
	int count = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &times[i].start, &times[i].end);
	}
	qsort(times, N, sizeof(times[0]), com);
	int cur_st = times[0].start;
	int cur_end = times[0].end;
	for (int i = 1; i < N; i++) {
		if (cur_end <= times[i].start) {
			count++;
			cur_end = times[i].end;
		}
	}
	printf("%d", count);
}