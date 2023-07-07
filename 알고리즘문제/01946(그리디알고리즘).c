#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int a;
	int b;
}list;
list l[100001];
int static c(list* a, list* b)
{
	if (a->a > b->a)
		return 1;
	else if (a->a < b->a)
		return -1;
}
int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		int cnt = 1;  
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d %d", &l[i].a, &l[i].b);
		
		qsort(l, n, sizeof(l[0]), c);  //a순위로 오름차순
		//b는 가장 최신 합격한 사람 순위보다 낮아야 함.
		int bmax = l[0].b; 
		for (int i = 1; i < n; i++) { 
			if (l[i].b < bmax) {
				cnt++;
				bmax = l[i].b;
			}
		}
		
		printf("%d\n", cnt);
	}
}
/* 반례 
2
5
1 5
2 3
3 4
4 2
5 1
7
1 4
2 3
3 2
4 1
5 7
6 6
7 5

ans :4 4
*/