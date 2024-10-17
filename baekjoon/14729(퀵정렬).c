#include <stdio.h>
#include <stdlib.h>

double score[10000001];
int static compare(double* a, double* b)
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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &score[i]);
	qsort(score, n, sizeof(score[0]), compare);
	for (int i = 0; i < 7; i++)
		printf("%.3lf\n", score[i]);
}