#include <stdio.h>
#include <stdlib.h>

int n, m;
int x[9];
int num[10001] = { 0 };
int res[9] = { 0 };

int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
}

void bt(int a, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);

		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!num[x[i]] || a == i) {
			if (a <= i) {
				res[cnt] = x[i];
				num[x[i]] = 1;
				bt(i, cnt + 1);
				num[x[i]] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	qsort(x, n, 4, c);
	bt(0, 0);
}