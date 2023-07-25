#include <stdio.h>
int n[1000001];
int m[1000001];

int main()
{
	while (1) {
		int x, y, res = 0;
		scanf("%d %d", &x, &y);
		if (x == 0 && y == 0)
			break;
            
		for (int i = 0; i < x; i++)
			scanf("%d", &n[i]);
		for (int i = 0; i < y; i++)
			scanf("%d", &m[i]);

		int s = 0;
		for (int i = 0; i < x; i++) {
			if (n[i] == m[s]) {
				res++;
				s++;
			}
			else if (n[i] > m[s]) {
				s++;
				i--;
            }
		}
		printf("%d\n", res);
	}
}