#include <stdio.h>
#include <stdlib.h>

int map[101][101] = { 0 };
typedef struct {
	int x;
	int y;
	char dir;
}Robot;

int main()
{
	Robot* list;
	int a, b, n, m;
	scanf("%d %d", &a, &b);
	scanf("%d %d", &n, &m);
	list = (Robot*)malloc(sizeof(Robot) * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %c", &list[i].x, &list[i].y, &list[i].dir);
		map[list[i].x][list[i].y] = i;  //로봇 번호로 위치 표시
	}

	int q, w, j;
	char e;
	for (int i = 0; i < m; i++) {
		scanf("%d %c %d", &q, &e, &w);  //q 로봇을 e방향 기준으로 w만큼 움직인다.
		if (e == 'F') {
			if (list[q].dir == 'N') {   //북쪽으로 움직일 때
				for (j = 1; j <= w; j++) {
					if (map[list[q].x][list[q].y + j] != 0) {
						printf("Robot %d crashes into robot %d", q, map[list[q].x][list[q].y + j]);
						return 0;
					}
					if (list[q].y + j > b) {
						printf("Robot %d crashes into the wall", q);
						return 0;
					}
				}
				j--;
				map[list[q].x][list[q].y] = 0;  //원래 위치의 로봇 제거
				map[list[q].x][list[q].y + j] = q;
				list[q].y += j;
			}
			else if (list[q].dir == 'S') {  //남쪽으로 움직일 때
				for (j = 1; j <= w; j++) {
					if (map[list[q].x][list[q].y - j] != 0) {
						printf("Robot %d crashes into robot %d", q, map[list[q].x][list[q].y - j]);
						return 0;
					}
					if (list[q].y - j < 1) {
						printf("Robot %d crashes into the wall", q);
						return 0;
					}
				}
				j--;
				map[list[q].x][list[q].y] = 0;  //원래 위치의 로봇 제거
				map[list[q].x][list[q].y - j] = q;
				list[q].y -= j;
			}
			else if (list[q].dir == 'E') {  //동쪽으로 움직일 때
				for (j = 1; j <= w; j++) {
					if (map[list[q].x + j][list[q].y] != 0) {
						printf("Robot %d crashes into robot %d", q, map[list[q].x + j][list[q].y]);
						return 0;
					}
					if (list[q].x + j > a) {
						printf("Robot %d crashes into the wall", q);
						return 0;
					}
				}
				j--;
				map[list[q].x][list[q].y] = 0;  //원래 위치의 로봇 제거
				map[list[q].x + j][list[q].y] = q;
				list[q].x += j;
			}
			else if (list[q].dir == 'W') {  //서쪽으로 움직일 때
				for (j = 1; j <= w; j++) {
					if (map[list[q].x - j][list[q].y] != 0) {
						printf("Robot %d crashes into robot %d", q, map[list[q].x - j][list[q].y]);
						return 0;
					}
					if (list[q].x - j < 1) {
						printf("Robot %d crashes into the wall", q);
						return 0;
					}
				}
				j--;
				map[list[q].x][list[q].y] = 0;  //원래 위치의 로봇 제거
				map[list[q].x - j][list[q].y] = q;
				list[q].x -= j;
			}
		}
		else if (e == 'L') {
			for (int j = 0; j < w; j++) {
				if (list[q].dir == 'N')
					list[q].dir = 'W';
				else if (list[q].dir == 'W')
					list[q].dir = 'S';
				else if (list[q].dir == 'S')
					list[q].dir = 'E';
				else if (list[q].dir == 'E')
					list[q].dir = 'N';
			}
		}
		else if (e == 'R') {
			for (int j = 0; j < w; j++) {
				if (list[q].dir == 'N')
					list[q].dir = 'E';
				else if (list[q].dir == 'E')
					list[q].dir = 'S';
				else if (list[q].dir == 'S')
					list[q].dir = 'W';
				else if (list[q].dir == 'W')
					list[q].dir = 'N';
			}
		}
	}
	free(list);
	printf("OK");
}

/*
Input
5 4
2 2
1 4 E
5 4 W
1 F 3
2 F 1

Output
Robot 2 crashes into robot 1

Input
1 3
2 1
1 1 N
1 2 N
1 F 2

Output
Robot 1 crashes into robot 2

*/