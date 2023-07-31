#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int start;
	int end;
	int value;
}Edge;
typedef struct {
	int n;
	Edge* list;
}Graph;

int parent[10001];
void init_parent() {
	for (int i = 0; i < 10001; i++)
		parent[i] = i;
}
int getparent(int n) {
	if (parent[n] == n)
		return n;
	else
		return parent[n] = getparent(parent[n]);
}
void set_union(int a, int b) {
	int root1 = getparent(a);
	int root2 = getparent(b);
	if (root1 < root2)
		parent[root2] = root1;
	else if (root1 > root2)
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

void graph_init(Graph* g, int n) {
	g->n = 0;
	g->list = (Edge*)calloc(n, sizeof(Edge));
}

void insert(Graph* g, int a, int b, int c) {
	g->list[g->n].start = a;
	g->list[g->n].end = b;
	g->list[g->n].value = c;
	g->n++;
}

int static c(Edge* a, Edge* b)
{
	if (a->value > b->value)
		return 1;
	else if (a->value < b->value)
		return -1;
}

int res = 0;
void kruskal(Graph* g, int n) {
	init_parent(n);   //정점의 개수만큼 초기화
	qsort(g->list, g->n, sizeof(g->list[0]), c);  //가중치 오름차순 정렬
	Edge temp;
	int kr_cnt = 0, idx = 0;
	int s, e;
	while (kr_cnt != n-1) {
		temp = g->list[idx++];
		s = temp.start;
		e = temp.end;
		if (sameparent(s, e) == 0) {
			set_union(s, e);
			res += temp.value;
			kr_cnt++;
		}
	}
}

int main()
{
	int v, e, a, b, c;
	Graph g;
	scanf("%d %d", &v, &e);
	graph_init(&g, e);
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		insert(&g, a, b, c);
	}

	kruskal(&g, v);
	printf("%d", res);
	free(g.list);
}

/* 예제 맞왜틀 -> 반례 하나
6 7
1 3 2
1 2 5
2 3 1
3 4 10
3 5 9
4 6 8
5 6 7
ans:27
*/