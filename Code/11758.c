#include <stdio.h>
typedef struct {
	int x;
	int y;
}Point;

int CCW(Point a, Point mid, Point b) {
	return (a.x * mid.y + mid.x * b.y + b.x * a.y - mid.x * a.y - b.x * mid.y - a.x * b.y);
}
int main() {
	Point a[3];
	for (int i = 0; i < 3; i++)
		scanf("%d %d", &a[i].x, &a[i].y);
	if (CCW(a[0], a[1], a[2]) < 0) {
		printf("-1");
	}
	else if (CCW(a[0], a[1], a[2]) > 0) {
		printf("1");
	}
	else {
		printf("0");
	}
}