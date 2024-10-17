#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int visited[101][101][101];
int mat[101][101][101];
int go[6][3] = { {0,0,-1},{0,0,1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0} };  //y,x,z
int res = 0;
int all = 0;
int n, m, h;

void init() {
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) 
				visited[i][j][k] = 0;
		}
	}
}

void bfs() {
	queue<tuple<int, int, int>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j][k] == 1) 
					q.push({ i,j,k });
			}
		}
	}
	int cnt = 0;

	while (!q.empty()) {
		int yy = get<0>(q.front());
		int xx = get<1>(q.front());
		int zz = get<2>(q.front());
		q.pop();
		if (cnt == all) {  //익혀야 할 토마토를 다 익혔다.
			for (int k = 0; k < h; k++) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						res = max(res, visited[i][j][k]);
					}
				}
			}
			break;
		}

		for (int i = 0; i < 6; i++) {
			int dy = yy + go[i][0];
			int dx = xx + go[i][1];
			int dz = zz + go[i][2];
			if (dy < 0 || dy >= n || dx < 0 || dx >= m || dz < 0 || dz >= h)
				continue;
			if (visited[dy][dx][dz])
				continue;
			if (mat[dy][dx][dz] == 0) {
				q.push({ dy,dx,dz });
				visited[dy][dx][dz] = visited[yy][xx][zz] + 1;
				cnt++;
			}
		}
	}
	if (cnt != all) //완성시킬 수 없는 경우
		res = -1;
}


int main()
{
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j][k];
				if (mat[i][j][k] == 0)
					all++;  //익혀야 할 토마토 개수 체크해둔다.
			}
		}
	}
	init();
	bfs();
	cout << res;
}