#include <iostream>
#include <queue>
#include <vector>
#define INF 999999999
using namespace std;

int v, e, k;
int dis[20001];
vector<pair<int, int>>mat[20001];

void dijkstra() {
	for (int i = 1; i <= v; i++) 
		dis[i] = INF;
	
	priority_queue<pair<int, int>> pq;  //max heap -> first값 기준 내림차순, first는 distance
	dis[k] = 0;  //시작지점부터 시작지점의 거리 0
	pq.push({ 0,k });  //시작정점 k부터 탐색 시작

	while (!pq.empty()) {
		int distance = -pq.top().first; 
		int cur = pq.top().second;  
		pq.pop();

		for (int i = 0; i < mat[cur].size(); i++) {
			int next = mat[cur][i].first;
			int cost = mat[cur][i].second;

			if (dis[next] > cost + distance) {
				dis[next] = cost + distance;
				pq.push({ -dis[next],next });
			}
		}
	}
}

void print_res() {
	for (int i = 1; i <= v; i++) {
		if (dis[i] != INF)
			cout << dis[i] << '\n';
		else
			cout << "INF\n";
	}
}

void input() {
	int a, b, c;
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		mat[a].push_back({ b,c });  //a정점에서부터 b까지 cost 는 c
	}
}

int main() {
	input();
	dijkstra();
	print_res();
}
