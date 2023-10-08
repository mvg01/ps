#include <iostream>
#define INF 1000000000
using namespace std;

int cost[1001][1001];
int value[1001];
int found[1001] = { 0 };
int n;  //정점갯수
int s, e;  //출발지 도착지

int choose() {  //n에서 가장 짧은 거리를 가진 정점
	int min = INF, res = 0;
	for (int i = 1; i <= n; i++) {
		if (!found[i] && min > value[i]) {
			res = i;
			min = value[i];
		}
	}
	return res;
}

void shortest_path(int start) {
	for (int i = 1; i <= n; i++) {
		if (cost[start][i] != INF)
			value[i] = cost[start][i];
		else
			value[i] = INF;
	}

	found[start] = 1;
	value[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		int u = choose();  //가장 가까운 정점 u
		found[u] = 1;

		if (u == e) //도착지
			break;
		
		for (int w = 1; w <= n; w++) {
			if (!found[w]) {
				if (value[u] + cost[u][w] < value[w])
					value[w] = value[u] + cost[u][w];
			}
		}
	}
}

int main()
{
	int m, U, V, W;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cost[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> U >> V >> W;
		if (cost[U][V] != INF)  //중복된 값이 올 수 있다.
			cost[U][V] = min(cost[U][V], W);
		else
			cost[U][V] = W;
	}
	cin >> s >> e;
	shortest_path(s);
	cout << value[e];
}