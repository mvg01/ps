#include <iostream>
#include <queue>
using namespace std;

int n, m;
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //북 동 남 서
int map[1001][1001];
int visited[1001][1001];
int res[1001][1001];

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!visited[yy + go[i][0]][xx + go[i][1]] && map[yy + go[i][0]][xx + go[i][1]] != 0) {
				visited[yy + go[i][0]][xx + go[i][1]] = 1;
				q.push({ yy + go[i][0],xx + go[i][1] });
				res[yy + go[i][0]][xx + go[i][1]] = res[yy][xx] + 1;
			}
		}
	}
}

int main()
{
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			res[i][j] = 0;
			cin >> map[i][j];

			if (map[i][j] == 2) {
				a = i;
				b = j;
			}
		}
	}
	bfs(a, b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (res[i][j] == 0 && map[i][j] == 1)  //원래 갈 수 없는 땅에 대한 판별
				cout << -1 << ' ';
			else
				cout << res[i][j] << ' ';
		}
		cout << '\n';
	}
}

/*
원래 갈 수 없는 땅
3 3
2 0 0
0 0 1
0 1 1

*/