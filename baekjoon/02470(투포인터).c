#include <stdio.h>
#include <stdlib.h>

int a[100001];
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
		scanf("%d", &a[i]);

	qsort(a, n, 4, compare);  //오름차순 정렬
	int start = 0, end = n - 1, sum = 0, min = 2000000000;  //정렬된 배열 안의 양쪽 끝에서 출발한다.
	int mina = 0, minb = 0;
	while (start <= end)
	{
		if (abs(a[start] + a[end]) < min) { //둘의 차이가 양수,음수 상관없기 떄문에 절댓값
			min = abs(a[start] + a[end]);
			mina = a[start];
			minb = a[end];
			if (a[start]+a[end] > 0) //양수 값이 더 크다면 end를 줄여줌 (오름차순 정렬)
				end--;
			else  
				start++;  
		}
		else
		{
			if (a[start] + a[end] > 0) 
				end--;
			else
				start++;
		}
		if (end == start)
			break;
	}
	printf("%d %d", mina, minb);
}

/* 확인해 볼 만한 반례들

5 
-1 -2 -3 -4 -5
ans: -1 -2

5
1 2 3 4 5
ans: 1 2

9
-100 -90 0 90 130 130 130 130 130
ans: -90 90

5
-99 -98 1 0 96
ans: 0 1

*/	