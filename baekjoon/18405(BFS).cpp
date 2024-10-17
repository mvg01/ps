#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, k, s, a, b;
int mat[201][201];
int visited[201][201];
int go[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<pair<int, int>>>v;

void bfs(int vir) {
	queue<pair<int, int>>q;
	for (int i = 0; i < v[vir].size(); i++) {
		if (visited[v[vir][i].first][v[vir][i].second] == 0) {
			q.push(v[vir][i]);
			visited[v[vir][i].first][v[vir][i].second] = 1;
		}
	}
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + go[i][0] >= 0 && yy + go[i][0] < n && xx + go[i][1] >= 0 && xx + go[i][1] < n)
			{
				if (!visited[yy + go[i][0]][xx + go[i][1]] && mat[yy + go[i][0]][xx + go[i][1]] == 0) {
					mat[yy + go[i][0]][xx + go[i][1]] = vir;
					v[vir].push_back({ yy + go[i][0],xx + go[i][1] });
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	v.resize(k + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] != 0) {
				v[mat[i][j]].push_back({i,j});
			}
			visited[i][j] = 0;
		}
	}
	cin >> s >> a >> b;
	for (int d = 0; d < s; d++) {
		for (int z = 1; z <= k; z++)
			bfs(z);
		
		if (mat[a - 1][b - 1] != 0)
			break;
	}
	cout << mat[a - 1][b - 1];
}