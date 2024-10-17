#include <iostream>
#include <queue>
using namespace std;

int r, c;
char mat[251][251];
bool visited[251][251];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int s = 0, w = 0;

void input() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'o')
				s++;
			else if (mat[i][j] == 'v')
				w++;
		}
	}
}

void bfs(int y,int x) {
	queue<pair<int, int>>q;
	q.push({ y,x });
	int ss = 0, ww = 0;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		if (mat[yy][xx] == 'v')  //늑대
			ww++;
		if (mat[yy][xx] == 'o')  //양
			ss++;
		for (int i = 0; i < 4; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];
			if (visited[cy][cx])
				continue;
			if (cy < 0 || cy >= r || cx < 0 || cx >= c)
				continue;
			if (mat[cy][cx] != '#') {
				q.push({ cy,cx });
				visited[cy][cx] = 1;
			}
		}
	}
	if (ww < ss)
		w -= ww;
	else
		s -= ss;
}

void solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mat[i][j] != '#' && !visited[i][j]) {
				visited[i][j] = 1;
				bfs(i, j);
			}
		}
	}
	cout << s << ' ' << w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}