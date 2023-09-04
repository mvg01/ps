#include <iostream>
#include <queue>
using namespace std;

int n;
int mat[65][65];
int visited[65][65];
int go[2] = { 1,0 };
bool chk = 0;

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y,x });

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		int iy = yy;
		int ix = xx;
		if (yy == n && xx == n) {
			chk = 1;
			break;
		}

		q.pop();
		for (int i = 0; i < 2; i++) {
			if (i == 0)
				yy += mat[yy][xx];
			else if (i == 1)
				xx += mat[yy][xx];

			if (yy >= 1 && yy <= n && xx >= 1 && xx <= n) {
				if (!visited[yy][xx]) {
					visited[yy][xx] = 1;
					q.push({ yy,xx });
				}
			}

			if (i == 0)
				yy = iy;
			else if (i == 1)
				xx = ix;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			visited[i][j] = 0;
		}
	}
	bfs(1, 1);
	if (chk)
		cout << "HaruHaru";
	else
		cout << "Hing";
}