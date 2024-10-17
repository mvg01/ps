#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int>v[20001];
int visited[20001] = { 0 };
int res = 0, dis = 0, cnt = 0; 

void input() {
	int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void bfs() {
	visited[1] = 1;
	queue<int>q;
	int size = v[1].size();
	for (int i = 0; i < size; i++) {
		q.push(v[1][i]);
		visited[v[1][i]] = 1;  //1에서 v[1][i]까지 거리는 1
	}
	while (!q.empty()) {
		int pp = q.front();
		q.pop();
		size = v[pp].size();
		for (int i = 0; i < size; i++) {
			if (!visited[v[pp][i]]) {
				visited[v[pp][i]] = visited[pp] + 1;
				q.push(v[pp][i]);
			}
		}
	}
	visited[1] = 0; //1에서부터 1까지 거리는 0으로 정정
}

void solve() {
	bfs();
	for (int i = 1; i <= n; i++) {
		if (visited[i] > dis) {
			dis = visited[i];
			res = i;
			cnt = 1;
		}
		else if(visited[i]==dis) 
			cnt++;
	}
	cout << res << ' ' << dis << ' ' << cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}