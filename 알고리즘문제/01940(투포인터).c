#include <stdio.h>
#include <stdlib.h>

int a[15001];
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
	int n, m, i, c = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	qsort(a, n, 4, compare);  //오름차순 정렬
	int start = 0, end = n - 1;
	while (start < end)
	{
		if (a[start] + a[end] == m) {  
			c++;
			start++;
			end--;
		}
		else if (a[start] + a[end] < m)  //둘이 합친게 m보다 작으면 start를 늘려 본다.
			start++;
		else  //둘이 합친게 m보다 커버리면 end를 줄여 본다.
			end--;
	}
	printf("%d", c);
}	