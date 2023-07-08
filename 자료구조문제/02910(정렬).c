#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cnt;
	int num;
}list;
int k[1001];  //원본 배열

int static com(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
int static c2(list* a, list* b)
{
	if (a->cnt < b->cnt)
		return 1;
	else if (a->cnt > b->cnt)
		return -1;
	else {  //개수가 같으면 원본 배열에서 먼저 오는게 앞으로
		for (int i = 0; i < 1001; i++) {
			if (k[i] == a->num) {
				return -1;
			}
			else if (k[i] == b->num) {
				return 1;
			}
		}
	}
}
int main()
{
	int arr[1001];
	int n, c, idx = 0;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		k[i] = arr[i];  //원본 배열 저장 (순서대로 출력할때 필요)
	}
	qsort(arr, n, 4, com);  //오름차순 정렬

	list l[1001];
	for (int i = 0; i < 1001; i++)
		l[i].cnt = 0;
	l[idx].cnt = 1;
	l[idx].num = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1])   //뒤의 숫자와 다르다면 숫자 갯수추가
			idx++;
		l[idx].cnt++;
		l[idx].num = arr[i]; 
	}
    //빈도가 높은 순으로 정렬, 같다면 원본배열에서 먼저나온 순
	qsort(l, idx + 1, sizeof(l[0]), c2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l[i].cnt; j++)
			printf("%d ", l[i].num);
	}
}