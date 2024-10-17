#include <iostream>
#include <queue>
using namespace std;
int n, m;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

int bfs(int y, int x, int* dis[], char* mat[]) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	dis[y][x] = 0;
	int d = 0;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		d = max(d, dis[yy][xx]);
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= n || xx + dx[i] < 0 || xx + dx[i] >= m)
				continue;
			if (yy + dy[i] == y && xx + dx[i] == x)  //처음 land 방문처리
				continue;
			if (dis[yy + dy[i]][xx + dx[i]] == 0 && mat[yy + dy[i]][xx + dx[i]] == 'L') {
				q.push({ yy + dy[i],xx + dx[i] });
				dis[yy + dy[i]][xx + dx[i]] = dis[yy][xx] + 1;
			}
		}
	}
	return d;
}

void init(int* dis[]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			dis[i][j] = 0;
	}
}

int main()
{
	char** mat;
	int** dis;
	int res = 0;
	cin >> n >> m;
	mat = new char* [n + 1];
	dis = new int* [n + 1];
	for (int i = 0; i < n; i++) {
		mat[i] = new char[m + 1];
		dis[i] = new int[m + 1];
	}
	for (int i = 0; i < n; i++)
		cin >> mat[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'L') {
				init(dis);
				//cout << bfs(i, j) << ' ';  각각 최대거리 확인
				res = max(bfs(i, j, dis, mat), res);
			}
		}
	}
	cout << res;

	for (int i = 0; i < n; i++) {
		delete[] mat[i];
		delete[] dis[i];
	}
	delete[] mat;
	delete[] dis;
}