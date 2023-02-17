#include <stdio.h>
#include <stdlib.h>

int A[100001];
int B[100001];

int static compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int binsearch(int data[], int n, int key) {
	int low, high;
	int mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == data[mid]) {            //탐색 성공
			return mid;
		}
		else if (key < data[mid]) {        //탐색 범위를 아래쪽으로
			high = mid - 1;
		}
		else if (key > data[mid]) {        //탐색 범위를 위쪽으로
			low = mid + 1;
		}
	}
	return -1;                            //탐색 실패
}

int main(void)
{
	int n, m, i, index;
	int count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	for (i = 0; i < m; i++)
		scanf("%d", &B[i]);

	qsort(A, n, sizeof(int), compare);  //이분탐색을 위한 정렬
	for (i = 0; i < m; i++)
	{
		index=binsearch(A, n, B[i]);
		if (index == -1)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}