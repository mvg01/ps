#include <iostream>
#include <queue>
#define INF 999999999
using namespace std;

int n, m;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
int ch[4];
int arr[101][101], dis[10001];
vector<pair<int, int>>mat[10001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j] - '0';
	}
}

void dijkstra() {
	for (int i = 0; i < n*m; i++)
		dis[i] = INF;
	priority_queue<pair<int, int>>pq;
	dis[0] = 0;
	pq.push({ 0,0 });  // 거리, 정점
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < mat[cur].size(); i++) {
			int next = mat[cur][i].first;
			int weight = mat[cur][i].second;
			if (dis[next] > dis[cur] + weight) {
				dis[next] = dis[cur] + weight;
				pq.push({ -dis[next],next });
			}
		}
	}
}

void solve() {
	//2차원 배열을 1차원 배열로, 4방향에 대해서 1인지 조사하고 1이면 가중치 1을 준다. 
	ch[0] = 1; ch[1] = n; ch[2] = -n; ch[3] = -1; 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {

				if (i + dy[k] < 0 || i + dy[k] >= m || j + dx[k] < 0 || j + dx[k] >= n) //범위 밖
					continue;

				if (arr[i + dy[k]][j + dx[k]] == 1)
					mat[i * n + j].push_back({ i * n + j + ch[k] , 1 });
				else
					mat[i * n + j].push_back({ i * n + j + ch[k] , 0 });
			}
		}
	}
	dijkstra();
	cout << dis[n * m - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}