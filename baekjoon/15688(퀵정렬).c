#include <stdio.h>
#include <stdlib.h>
int a[1000001];
int static compare(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d",&a[i]);
	qsort(a, n, 4, compare);
	for (i = 0; i < n; i++)
		printf("%d\n", a[i]);
}
