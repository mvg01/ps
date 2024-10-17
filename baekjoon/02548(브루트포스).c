#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[20001];
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
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	qsort(a, n, 4, compare);
	int min = 199970001, res = 0;  //min의 최대 차이는 10000-1 의 차이가 19999개 있는 (9999*19999)이다. 
	for (int i = 0; i < n; i++)
	{
		int minus = 0;
		for (int j = 0; j < i; j++)
			minus += abs(a[i] - a[j]); 
		for (int j = i + 1; j < n; j++)
			minus += abs(a[i] - a[j]);

		//printf("%d ", minus); //그때 그때 차이값을 보기 위한 출력문
		if (min > minus) {
			min = minus;
			res = a[i];
		}
	}
	printf("%d", res);
}