#include <iostream>
#include <vector>
using namespace std;

vector<int>v[2001];
int visited[2001] = { 0 };
bool res = 0;

void init() {
	for (int i = 0; i < 2001; i++)
		visited[i] = 0;
}

void dfs(int x,int cnt) {
	if (cnt == 4) {  //깊이가 4인 경우가 나왔다면 결과가 1
		res = 1;
		return;
	}

	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i]]) {
			visited[v[x][i]] = 1;
			dfs(v[x][i], cnt + 1);
			if (res)
				break;
			visited[v[x][i]] = 0;
		}
	}
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		init();
		visited[i] = 1; 
		dfs(i, 0);
		if (res) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}

/*
도움받은 반례

5 4
0 1
1 2
2 3
3 0

ans : 0
*/