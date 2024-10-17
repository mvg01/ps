#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int go[6][2] = { {-2,-1},{-2,1},{0,-2,},{0,2},{2,-1},{2,1} };
int visited[201][201];
int n, r1, c1, r2, c2;
int res = 400000;
int dis[201][201];

void bfs() {
	queue<pair<int, int>>q;
	q.push({ r1,c1 });
	dis[r1][c1] = 0;
	visited[r1][c1] = 1;
	while (!q.empty()) {
		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();
		if (rr == r2 && cc == c2) {
			res = min(res, dis[rr][cc]);
			break;
		}
		for (int i = 0; i < 6; i++) {
			if (rr + go[i][0] < 0 || rr + go[i][0] >= n || cc + go[i][1] < 0 || cc + go[i][1] >= n)
				continue;
			if (visited[rr + go[i][0]][cc + go[i][1]] == 1)
				continue;
			
			dis[rr + go[i][0]][cc + go[i][1]] = dis[rr][cc] + 1;
			q.push({ rr + go[i][0],cc + go[i][1] });
			visited[rr + go[i][0]][cc + go[i][1]] = 1;
		}
	}
}

int main()
{
	cin >> n >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dis[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	bfs();
	if (res != 400000)
		cout << res;
	else
		cout << -1;
}