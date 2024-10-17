#include <stdio.h>
#include <stdlib.h>

int static compare(int* a, int* b)
{
	if (*a < *b)
		return 1;
	else if (*a > *b)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n, i, j, cnt = 0;
	int solved[67], copy[67];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &solved[i]);
		copy[i] = solved[i];
	}
	qsort(copy, n, 4, compare);  //내림차순 정렬

	int s = copy[4];  //5등인 사람의 점수
	for (i = 5; i < n; i++)
	{
		if (s == copy[i])  //같은 점수인 사람만 찾아서 증가시키면 해결된다.
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}