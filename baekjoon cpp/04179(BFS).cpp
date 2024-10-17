#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999
using namespace std;

int r, c;
int s_y, s_x, f = 0;
int res = INF;
char mat[1001][1001];
int dis_time[1001][1001];   //지훈이가 방문한 시간
int visited[1001][1001];  //불이 방문한 시간
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
vector<pair<int, int>>fire;

void input() {
	cin >> r >> c;  //세로 가로
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'J') {
				s_y = i;
				s_x = j;
			}
			else if (mat[i][j] == 'F') {
				fire.push_back({ i,j });
				f++;
			}
			else if (mat[i][j] == '#') {
				visited[i][j] = INF;  //불이 닿을 수 없다
			}
		}
	}
}

void bfs() {  //지훈이의 이동경로 예상
	queue<pair<int, int>>q;
	q.push({ s_y,s_x });
	dis_time[s_y][s_x] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		if (yy == 0 || yy == r - 1 || xx == 0 || xx == c - 1) {
			res = dis_time[yy][xx];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];
			int time = dis_time[yy][xx];
			if (dis_time[cy][cx])
				continue;
			if (cy < 0 || cy >= r || cx < 0 || cx >= c)
				continue;

			//통로이고, 지훈이가 불길이 도달한 시간보다 빠르다면(혹은 불길이 오지 못하면) 갈 수 있다
			if (mat[cy][cx] == '.' && (visited[cy][cx] > time + 1) || visited[cy][cx] == 0) {
				q.push({ cy,cx });
				dis_time[cy][cx] = time + 1;
			}
		}
	}
}

void bfs_fire() {  //불길의 이동경로
	queue<pair<int, int>>q;
	for (int i = 0; i < f; i++) {
		q.push(fire[i]);
		visited[fire[i].first][fire[i].second] = 1;
	}
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cy = yy + dy[i];
			int cx = xx + dx[i];
			int time = visited[yy][xx];
			if (visited[cy][cx] < INF && visited[cy][cx] >= 1)
				continue;
			if (cy < 0 || cy >= r || cx < 0 || cx >= c)
				continue;
			if (mat[cy][cx] != '#') {
				q.push({ cy,cx });
				visited[cy][cx] = time + 1;
			}
		}
	}
}

void solve() {
	bfs_fire();
	bfs();
	// 사실 모든 거리(visited,dis_time) 값에 1씩 빼줘야 한다. 
	// 하지만 지훈이가 좌표 끝에 도달하면 1이라는 시간이 더필요하므로 그냥 둠
	if (res != INF)
		cout << res;
	else
		cout << "IMPOSSIBLE";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}