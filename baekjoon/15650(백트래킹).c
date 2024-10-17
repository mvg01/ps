#include <stdio.h>

int n, m;
int num[9] = { 0 };
void bt(int a, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (num[i] == 1)
				printf("%d ", i);
		}
		printf("\n");
		return;
	}

	for (int i = a; i <= n; i++) {
		if (!num[i]) {
			num[i] = 1;
			bt(i + 1, cnt + 1);
			num[i] = 0;
		}
	}
}

int main() 
{
	scanf("%d %d", &n, &m);
	bt(1, 0);
}