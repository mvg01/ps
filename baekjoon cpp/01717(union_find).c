#include <stdio.h>
#include <stdlib.h>

int parent[1000001];

int getparent(int n) {
	if (parent[n] == n)
		return n;
	else
		return parent[n] = getparent(parent[n]);
}

void set_union(int x, int y) {
	int root1 = getparent(x);
	int root2 = getparent(y);
	if (root1 < root2)
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
	int n, m, a, b, t;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= 1000000; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0)
			set_union(a, b);
		else if (t == 1) {
			if (sameparent(a, b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}