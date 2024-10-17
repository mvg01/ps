#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> v[801];
int dis[801] = { 0 };
long long res = INF;  //INF를 더하다가 overflow 방지

void input() {
	int a, b, c;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		a--; b--;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cin >> v1 >> v2;
	v1--; v2--;
}

void init() {
	for (int i = 0; i < n; i++) 
		dis[i] = INF;
}

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq; //max heap -> first값 기준
	pq.push({ 0,start });
	dis[start] = 0;
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int cost = v[cur][i].second;

			if (dis[next] > cost + distance) {
				dis[next] = cost + distance;
				pq.push({ -dis[next],next });
			}
		}
	}
}

void solve() {
	init();
	dijkstra(0);  // 0에서 v1, v2 까지의 거리
	long long dis1 = dis[v1], dis2 = dis[v2];

	init();
	dijkstra(v1);  // v1 에서 v2, n까지 거리
	dis1 += dis[v2];
	long long plus2 = dis[n - 1];

	init();
	dijkstra(v2); // v2 에서 v1, n까지 거리
	dis2 += dis[v1];
	long long plus1 = dis[n - 1];

	res = min(dis1 + plus1, dis2 + plus2);

	if (res < INF)
		cout << res;
	else
		cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}