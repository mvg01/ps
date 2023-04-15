#include <stdio.h>

char map[1001][1001];
int main()
{
	int n, i, j;  // i 세로  j 가로
	int check = 0, h_i = 0, h_j = 0;  //심장의 위치
	scanf("%d", &n);
	for (i = 1; i <= n; i++)  //세로
	{
		for (j = 1; j <= n; j++) { //가로
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '*' && check == 0) {
				check = 1;
				h_i = i + 1;
				h_j = j;
			}
		}
	}

	int r_arm=0, l_arm=0, r_leg=0, l_leg=0, hurry=0;  //다리,팔,허리
	for (j = 1; j < h_j; j++) {  //왼쪽 팔
		if (map[h_i][j] == '*')
			l_arm++;
	}
	for (j = h_j + 1; j <= n; j++) {  //오른쪽 팔
		if (map[h_i][j] == '*')
			r_arm++;
	}
	int chk;   //허리 위치로 다리 위치를 알기위해 만든 chk
	for (i = h_i + 1; i <= n; i++) {  //허리
		if (map[i][h_j] == '*') {
			hurry++;
			chk = i;
		}
		else
			break;
	}
	for (i = chk + 1; i <= n; i++) {  //왼쪽 다리 
		if (map[i][h_j - 1] == '*')
			l_leg++;
	}
	for (i = chk + 1; i <= n; i++) {  //오른쪽 다리
		if (map[i][h_j + 1] == '*')
			r_leg++;
	}

	printf("%d %d\n%d %d %d %d %d", h_i, h_j, l_arm, r_arm, hurry, l_leg, r_leg);
}