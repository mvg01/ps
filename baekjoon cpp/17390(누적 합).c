#include <stdio.h>
#include <stdlib.h>
int a[300001];
int sum[300001];

int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
int main()
{	
	int n, q, l, r;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, 4, c);
	sum[0] = 0;
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i - 1];
	sum[n] = sum[n - 1] + a[n - 1];
	

	for (int i = 0; i < q; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
}