#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int l, r, c;
char map[31][31][31];  //층,행,열
int dis[31][31][31];
bool visited[31][31][31];

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int dz[2] = { 1,-1 };
int res = 0;

void bfs(int z, int y, int x) {
	queue<tuple<int, int, int>>q;
	q.push({ z,y,x });

	while (!q.empty()) {
		int zz = get<0>(q.front());
		int yy = get<1>(q.front());
		int xx = get<2>(q.front());
		if (map[zz][yy][xx] == 'E') {
			res = dis[zz][yy][xx];
			break;
		}
		q.pop();

		for (int i = 0; i < 2; i++) {
			if (zz + dz[i] < 0 || zz + dz[i] >= l)
				continue;
			if (map[zz+dz[i]][yy][xx] == '.'|| map[zz + dz[i]][yy][xx] == 'E') {
				if (visited[zz + dz[i]][yy][xx] == 0) {
					dis[zz + dz[i]][yy][xx] = dis[zz][yy][xx] + 1;
					visited[zz + dz[i]][yy][xx] = 1;
					q.push({ zz + dz[i],yy,xx });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] < 0 || yy + dy[i] >= r || xx + dx[i] < 0 || xx + dx[i] >= c) 
				continue;
			if (map[zz][yy + dy[i]][xx + dx[i]] == '.' || map[zz][yy + dy[i]][xx + dx[i]] == 'E') {
				if (visited[zz][yy + dy[i]][xx + dx[i]] == 0) {
					dis[zz][yy + dy[i]][xx + dx[i]] = dis[zz][yy][xx] + 1;
					visited[zz][yy + dy[i]][xx + dx[i]] = 1;
					q.push({ zz,yy + dy[i],xx + dx[i] });
				}
			}
		}
	}
}

int main()
{
	while (1) {
		int startL, startR, startC;
		res = 0;
		cin >> l >> r >> c;
		if (l == 0)
			break;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> map[i][j];

				for (int k = 0; k < c; k++) {
					visited[i][j][k] = 0;
					dis[i][j][k] = 0;
					if (map[i][j][k] == 'S') {
						startL = i;
						startR = j;
						startC = k;
					}
				}
			}
			getchar();
		}

		bfs(startL, startR, startC);
		if (res != 0)
			cout << "Escaped in " << res << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
}