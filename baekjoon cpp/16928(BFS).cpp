#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int mat[101] = { 0 };
int visited[101] = { 0 };
int dis[101] = { 0 };
int dice[] = { 1,2,3,4,5,6 };
int res = 1000;

void bfs() {
	int point = 1;
	visited[point] = 1;
	dis[point] = 0;
	queue<int>q;
	q.push(point);

	while (!q.empty()) {
		int pp = q.front();
		q.pop();
		if (pp == 100)
			res = min(dis[100], res);
		
		visited[pp] = 1;
		for (int i = 0; i < 6; i++) {
			if (pp + dice[i] > 100)  //범위 밖
				break;

			if (!visited[pp + dice[i]]) {
				if (mat[pp + dice[i]] == 0) {
					q.push(pp + dice[i]);
					dis[pp + dice[i]] += dis[pp] + 1;
					visited[pp + dice[i]] = 1;
				}
				else {
					if (!visited[mat[pp + dice[i]]]) {  //중복 방문 방지
						q.push(mat[pp + dice[i]]);
						dis[mat[pp + dice[i]]] += dis[pp] + 1;
						//방문처리 2가지를 해준다. 
						visited[mat[pp + dice[i]]] = 1;
						visited[pp + dice[i]] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	int u, v;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> u >> v;
		mat[u] = v;
	}
	bfs();
	cout << res;
}

/*
훌륭한 반례 모음
1 1
13 99
8 7

ans:3

2 1
2 60
21 99
61 20

ans:4
*/