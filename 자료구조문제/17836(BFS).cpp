#include <iostream>
#include <queue>
using namespace std;
#define INF 10000001

int mat[101][101];
int visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int n, m, t;
int gram_x, gram_y;  //무기의 위치 정보
int res = INF;
int gram = INF;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) 
			visited[i][j] = 0;
	}
}

void bfs1(int y, int x, int time) {  //그람 없는 상황에서
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		if (yy == n && xx == m)  //최단거리
			res = min(res, visited[yy][xx]);
		
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] <= 0 || yy + dy[i] > n || xx + dx[i] <= 0 || xx + dx[i] > m)
				continue;
			if (!visited[yy + dy[i]][xx + dx[i]] && mat[yy + dy[i]][xx + dx[i]] != 1) {
				visited[yy + dy[i]][xx + dx[i]] = visited[yy][xx] + 1;
				q.push({ yy + dy[i], xx + dx[i] });
			}
		}
	}
}

void bfs2(int y, int x, int time) {  //그람부터 찾으러 가기
	queue<pair<int, int>>q;
	q.push({ y,x });
	visited[y][x] = 0; 

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();

		if (yy == gram_y && xx == gram_x)  //최단거리
			gram = min(gram, visited[yy][xx]);

		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] <= 0 || yy + dy[i] > n || xx + dx[i] <= 0 || xx + dx[i] > m)
				continue;
			if (!visited[yy + dy[i]][xx + dx[i]] && mat[yy + dy[i]][xx + dx[i]] != 1) {
				visited[yy + dy[i]][xx + dx[i]] = visited[yy][xx] + 1;
				q.push({ yy + dy[i], xx + dx[i] });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 2) {
				gram_x = j;
				gram_y = i;
			}
		}
	}
	init();
	bfs1(1, 1, 0);
	init();
	bfs2(1, 1, 0);
	if (gram != INF) { //그람 찾은 이후로는 최단거리로
		int plus = (n - gram_y) + (m - gram_x); 
		res = min(res, gram + plus);
	}
	if (t >= res)
		cout << res;
	else
		cout << "Fail";
}