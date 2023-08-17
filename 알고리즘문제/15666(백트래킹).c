#include <stdio.h>
#include <stdlib.h>

int n, m;
int visited[9] = { 0 };
int x[9];
int res[9];
int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
}

void bt(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] != m && prev != x[i]&&res[idx-1]<=x[i]) {
			visited[i]++;
			res[idx] = x[i];
			prev = x[i];
			bt(cnt + 1, idx + 1);
			visited[i]--;
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