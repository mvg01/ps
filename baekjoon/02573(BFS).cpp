#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int mat[301][301];
int visited[301][301];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int n, m;
int res = 0;

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
}

void bfs(int i,int j) {  //빙산의 덩어리 개수 파악 bfs
	queue<pair<int, int>>q;  
	q.push({ i,j });
	visited[i][j] = 1;
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] >= n || yy + dy[i] < 0 || xx + dx[i] >= m || xx + dx[i] < 0)
				continue;
			if (visited[yy + dy[i]][xx + dx[i]])
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] > 0) {
				q.push({ yy + dy[i] ,xx + dx[i] });
				visited[yy + dy[i]][xx + dx[i]] = 1;
			}
		}
	}
}

void melting() {
	queue<pair<int, int>>q; //빙산을 모두 큐에 담은 후 녹는과정 진행
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0)
				q.push({ i,j });
		}
	}
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (yy + dy[i] >= n || yy + dy[i] < 0 || xx + dx[i] >= m || xx + dx[i] < 0)
				continue;
			if (mat[yy + dy[i]][xx + dx[i]] == 0)
				cnt++;
		}
		mat[yy][xx] -= cnt;
		if (mat[yy][xx] == 0)
			mat[yy][xx] = -1;
	}
}

void solve() {
	while (1) {
		int h = 0;
		init();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j] == 0 && mat[i][j] != 0) {
					bfs(i, j);
					h++;
				}
			}
		}
		if (h >= 2) //두 덩이 이상의 빙산이 만들어짐
			break;
		else if (h == 0) {  //빙산이 없을경우
			res = 0;
			break;
		}

		melting();  //좌우 4방향 중 바다 개수만큼 녹음, 여기서 바다는 0인데 만약 빙산이 녹아서 0이되면 잠깐 -1로 바꿔줘야 함!
		for (int i = 0; i < n; i++) {   
			for (int j = 0; j < m; j++) {
				if (mat[i][j] < 0) //melting이 끝난 후 바다는 모두 0으로 바꿔준다.
					mat[i][j] = 0;
			}
		}
		res++; 
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