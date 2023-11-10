#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
char mat[3003][3003];
int visited[3003][3003];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int dis = 10000;

void bfs(int y, int x) {
	queue<pair<int, int>>q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		if (mat[yy][xx] == '3') {
			dis = min(dis, visited[yy][xx]);
		}
		else if (mat[yy][xx] == '4') {
			dis = min(dis, visited[yy][xx]);
		}
		else if (mat[yy][xx] == '5') {
			dis = min(dis, visited[yy][xx]);
		}

		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] !='1' && !visited[yy + dy[i]][xx + dx[i]]) {
				visited[yy + dy[i]][xx + dx[i]] = visited[yy][xx] + 1;
				q.push({ yy + dy[i],xx + dx[i] });
			}
		}
	}
}

int main()
{
	int start_x, start_y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '2') {
				start_x = j;
				start_y = i;
			}
		}
	}
	bfs(start_y, start_x);
	if (dis != 10000)
		cout << "TAK\n" << dis - 1;
	else
		cout << "NIE";
}