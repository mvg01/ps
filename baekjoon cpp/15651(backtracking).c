#include <stdio.h>

int n, m;
int num[9] = { 0 };
int res[9] = { 0 };

void bt(int a, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", res[i]);

		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		res[cnt] = i;
		num[i] = 1;
		bt(i, cnt + 1);
		num[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	bt(1, 0);
}