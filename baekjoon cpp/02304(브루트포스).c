#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int l;
	int h;
}rec;

int static c(rec *a, rec* b)
{
	if (a->l > b->l)
		return 1;
	else if (a->l < b->l)
		return -1;
}

int main()
{
	int n, i, res = 0;
	rec r[1001];
	scanf("%d", &n);
	int hmax = 0;
	for (i = 0; i < n; i++) {
		scanf("%d %d", &r[i].l, &r[i].h);
		if (hmax < r[i].h)
			hmax = r[i].h;
	}
	if (n == 1) {  //n이 1일 때
		printf("%d", r[0].h);
		return 0;
	}

	qsort(r, n, sizeof(r[0]), c);  // l기준으로 정렬

	int cur = r[0].h, prev = r[0].l;
	for (i = 1; i < n; i++) {  // 가장 높은 hmax가 나올때까지의 넓이
		if (r[i].h == hmax) {
			res += cur * (r[i].l - prev);
			res += hmax;
			prev = r[i].l + 1;
			cur = r[i].h;
			break;
		}

		else if (cur >= r[i].h) {
			res += cur * (r[i].l - prev);
			prev = r[i].l;
		}
		else if(cur<r[i].h) {
			res += cur * (r[i].l - prev);
			cur = r[i].h;
			prev = r[i].l;
		}
		//printf("%d ", res);
	}

	// hmax의 오른쪽 부분 넓이 -> 오른쪽 벽에서부터 구한다.
	int idx = i;
	cur = r[n - 1].h, prev = r[n - 1].l;
	for (int i = n - 2; i >= idx; i--) {
		if (cur >= r[i].h) {
			res += cur * (prev - r[i].l);
			prev = r[i].l;
		}
		else if (cur < r[i].h) {
			res += cur * (prev - r[i].l);
			cur = r[i].h;
			prev = r[i].l;
		}
		//printf("%d ", res);
	}

	printf("%d", res);
}