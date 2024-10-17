#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int mat[101][71];
bool visited[101][71];
int dx[8] = { 1,0,-1,1,-1,1,0,-1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
vector<pair<int, int>>v;  //산봉우리 재탐색 방지 벡터
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
	}
	int size = v.size();
	for (int i = 0; i < size; i++)
		visited[v[i].first][v[i].second] = 1;
}

bool bfs(int y, int x) {
	bool chk = 1;  //산봉우리 여부
	queue<pair<int, int>>q;
	vector<pair<int, int>>temp;
	q.push({ y,x });
	visited[y][x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		int h = mat[yy][xx];
		q.pop();
		for (int i = 0; i < 8; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];
			if (cy < 0 || cy >= n || cx < 0 || cx >= m)
				continue;
			if (mat[cy][cx] > h) {
				chk = 0; //산봉우리 될 수 없음
				break;
			}
			if (visited[cy][cx])
				continue;
			if (mat[cy][cx] == h) {
				q.push({ cy,cx });
				visited[cy][cx] = 1;
				temp.push_back({ cy,cx });
			}
		}
	}
	if (!chk) 
		return 0;
	else {
		for (int i = 0; i < temp.size(); i++)
			v.push_back({ temp[i].first,temp[i].second });
		return 1;
	}
}

void solve() {
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0 && !visited[i][j]) {
				if (bfs(i, j)) {
					res++;
					//cout << i << ' ' << j << '\n';
				}
				init();
			}
		}
	}
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}