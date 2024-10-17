#include <stdio.h>

int map[105][105] = { 0 };
int main()
{
	int n, m, i, j, k;
	int x1, x2, y1, y2;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (j = x1; j <= x2; j++) {
			for (k = y1; k <= y2; k++)
				map[j][k]++;
		}
	}
	int cnt = 0;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			if (map[i][j] > m)
				cnt++;
		}
	}
	printf("%d", cnt);
}
