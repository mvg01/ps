#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
char mat[101][101];
bool visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
vector<tuple<int, int, int>>v;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
}

int chk(int y, int x) {
	int len = 0, idx = 0;
	while (1) {
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (dy[i] == 1)
				yy += idx;
			else if(dy[i]==-1)
				yy -= idx;
			if (dx[i] == 1)
				xx += idx;
			else if (dx[i] == -1)
				xx -= idx;

			if (mat[yy][xx] == '.' || yy < 0 || yy >= n || xx < 0 || xx >= m)
				return idx;
		}
		idx++;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '*') {
				int len = chk(i, j);
				if (len > 0) {
					visited[i][j] = 1;
					for (int a = 1; a <= len; a++) {
						visited[i][j + a] = 1;
						visited[i][j - a] = 1;
						visited[i + a][j] = 1;
						visited[i - a][j] = 1;
					}
				}
				while (len != 0) {
					v.push_back({ i + 1,j + 1,len });
					len--;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '*' && !visited[i][j]) {
				cout << -1;
				return;
			}
		}
	}
	int size = v.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}