#include <stdio.h>
#include <stdlib.h>

int n;  //정점의 개수
int* adj_mat[100001];
int* visited;
int* res;
int* size;

void init()
{
	visited = (int*)calloc(n + 1, sizeof(int));
	res = (int*)calloc(n + 1, sizeof(int));
	size = (int*)calloc(n + 1, sizeof(int));
}

void insert(int s, int e)
{
    //정점의 인접 행렬 받을때마다 realloc로 공간할당해서 메모리초과를 막는다.
	adj_mat[s] = (int*)realloc(adj_mat[s], sizeof(int) * (size[s] + 1));  
	adj_mat[e] = (int*)realloc(adj_mat[e], sizeof(int) * (size[e] + 1));

	adj_mat[s][size[s]++] = e;
	adj_mat[e][size[e]++] = s;
}

void print()
{
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < size[i]; j++) {
			printf("%2d ", adj_mat[i][j]);
		}
		printf("\n");
	}
}

int idx = 1;
void dfs(int v)
{
	int w;
	visited[v] = 1;
	//printf("%d\n", v);
	res[v] = idx++;
	for (int i = 0; i < size[v]; i++)
	{
		w = adj_mat[v][i];
		if (visited[w]==0)
			dfs(w);
	}
}

int static compare(const void* a, const void* b)
{
	int* pa = (int*)a;
	int* pb = (int*)b;

	if (*pa > *pb)
		return 1;
	else if (*pa < *pb)
		return -1;
	else
		return 0;
}
int main()
{
	int m, r, a, b;
	scanf("%d %d %d", &n, &m, &r);
	init();
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		insert(a, b);
	}
	for (int i = 1; i <= n; i++) 
		qsort(adj_mat[i], size[i], sizeof(adj_mat[i][0]), compare);
	
	dfs(r);
	for (int i = 1; i <= n; i++) 
		printf("%d\n", res[i]);
	
	free(visited);
	free(res);
	for (int i = 1; i <= n; i++) {
		free(adj_mat[i]);
	}
	free(size);
}