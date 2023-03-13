#include <stdio.h>
int a[100001];
int sum[100001];
int main(void)
{
	int n, m, l;
	scanf("%d %d", &n, &m);
	for (l = 1; l <= n; l++) 
	{
		scanf("%d", &a[l]);
		sum[l] += sum[l - 1] + a[l];
	}
	int i, j;
	while (m--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}
}