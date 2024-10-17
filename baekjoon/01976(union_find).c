#include <stdio.h>
#include <stdlib.h>

int mat[201][201];
int parent[201];

void init() {
	for (int i = 0; i < 201; i++)
		parent[i] = i;
}


int getparent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = getparent(parent[x]);
}

void set_union(int i, int j) {
	int a = getparent(i);
	int b = getparent(j);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}



int main()
{
	int n, m, city[1001];
	scanf("%d %d", &n, &m);
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mat[i][j]);
			if (mat[i][j] == 1)
				set_union(i, j);
		}
	}
	for (int i = 0; i < m; i++) 
		scanf("%d", &city[i]);

	for (int i = 1; i < m; i++) {
		if (getparent(city[i - 1]) != getparent(city[i])) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
}