#include <stdio.h>
#include <string.h>

int main()
{
	char go[501];
	int xmove[4] = { 0,-1,0,1 };
	int ymove[4] = { 1,0,-1,0 };
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", go);
		int golen = strlen(go), cur = 0;  ////방향: 북 서 남 동
		int xmax = 0, ymax = 0, xmin = 0, ymin = 0;
		int x = 0, y = 0;
		for (int i = 0; i < golen; i++) {
			if (go[i] == 'F')
			{
				x += xmove[cur];
				y += ymove[cur];
				if (xmax < x)
					xmax = x;
				else if (ymax < y)
					ymax = y;
				else if (xmin > x)
					xmin = x;
				else if (ymin > y)
					ymin = y;
			}
			else if (go[i] == 'B')
			{
				x -= xmove[cur];
				y -= ymove[cur];
				if (xmax < x)
					xmax = x;
				else if (ymax < y)
					ymax = y;
				else if (xmin > x)
					xmin = x;
				else if (ymin > y)
					ymin = y;
			}
			else if (go[i] == 'R') {
				cur = (cur - 1 + 4) % 4;
			}
			else if (go[i] == 'L') {
				cur = (cur + 1) % 4;
			}
		}
		//printf("%d %d %d %d\n", xmax, xmin, ymax, ymin);
		printf("%d\n", (xmax - xmin) * (ymax - ymin));
	}
}
/*
1
FRFRFRF
ans:1
*/