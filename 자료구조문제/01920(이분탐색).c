/* bsearch의 return 값: key에 해당하는 값을 찾을 경우 : key가 위치한 주소(배열의 주소)
                                값을 찾지 못했을 경우 : NULL                    

			배열의 개수 n : O(log n)의 시간복잡도

bsearch(찾을 값의 주소, 찾을 대상의 배열, 배열 개수, 배열 크기, 비교포인터 함수)      */

#include <stdio.h>
#include <stdlib.h>

int A[100001];
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
	int n, m, i, x;
	//int* p;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	qsort(A, n, sizeof(int), compare);

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		printf("%d\n", bsearch(&x, A, n, sizeof(int), compare)!=NULL);  //bsearch가 NULL값을 리턴한게 아니면 1 출력
		
		/* 추가 이 문제는 단순히 x가 배열 A안에 있는지 없는지 여부를 물었다. 만약 배열 인덱스값을 구해야한다면?

		if (p = bsearch(&x, A, n, sizeof(int), compare))
			printf("%d\n",(int)(p-A));      A는 정렬되어있는 배열임                                       */

	}
	return 0;
}