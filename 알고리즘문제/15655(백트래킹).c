#include <stdio.h>
#include <stdlib.h>

int n, m;
int x[9];
int num[10001] = { 0 };
int res[9] = { 0 };

void bt(int a, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	for (int i = a; i < n; i++) {
		if (!num[i]) {
			res[cnt] = x[i];
			num[i] = 1;
			bt(i + 1, cnt + 1);
			num[i] = 0;
		}
	}
}

int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	qsort(x, n, 4, c);
	bt(0, 0);
}