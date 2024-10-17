#include <stdio.h>
#include <stdlib.h>

int a[10001];
int parent[10001];

int getparent(int n) {
	if (parent[n] == n)
		return n;
	else
		return parent[n] = getparent(parent[n]);
}

void set_union(int x, int y) {
	int root1 = getparent(x);
	int root2 = getparent(y);
	if (a[root1] < a[root2])
		parent[root2] = root1;
	else
		parent[root1] = root2;
}

int sameparent(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a == b)
		return 1;
	else
		return 0;
}

int main()
{
	int n, m, k, v, w;
	long long res = 0;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		parent[i] = i;
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &v, &w);
		if (!sameparent(v, w)) //만약 v와 w의 부모가 같지 않다면
			set_union(v, w);   
	}

	for (int i = 1; i <= n; i++) {
		if (parent[i] == i)    //연결된 친구 포함이고 가장 싼 가격임
			res += a[i];
		if (res > k) {
			printf("Oh no");
			return 0;
		}
	}
	printf("%lld", res);
}