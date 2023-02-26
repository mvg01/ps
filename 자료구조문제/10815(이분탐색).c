#include <stdio.h>
#include <stdlib.h>

int a[500001];
int b[500001];
int static compare(int* a, int* b) 
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
	int n, m, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &b[i]);
	qsort(a, n, 4, compare);

	for (i = 0; i < m; i++)
	{
		if (bsearch(&b[i], a, n, sizeof(int), compare) != NULL)
			printf("1 ");
		else
			printf("0 ");
	}
}