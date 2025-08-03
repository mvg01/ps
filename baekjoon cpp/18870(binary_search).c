#include <stdio.h>
#include <stdlib.h>
int x[1000001];
int y[1000001];
int z[1000001];
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
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		y[i] = x[i];  //y는 x의 원본
	}
	qsort(x, n, 4, compare);
	int index = 0;
	for (i = 0; i < n; i++)  //정렬된 x에서 중복된 값들을 제거해줘야함
	{
		if (x[i] != x[i + 1]) {
			z[index] = x[i];  //아예 z라는 배열로 직접 인덱스를 늘려가며 만들자
			index++;
		}
	}

	int* p;  //이분탐색을 위한 포인터
	for (i = 0; i < n; i++)
	{
		//bsearch(찾는 대상의 주소값 처음에 복사한 y, 찾을 대상의 배열, 찾을 대상 배열의 크기, 자료형크기, 비교함수)
		p = bsearch(&y[i], z, index, sizeof(int), compare);   //p는 z[i]가 위치해있는 주소값
		printf("%d ", (int)(p - z));  //탐색성공하고 찾는 대상의 배열의 인덱스 출력
	}
}