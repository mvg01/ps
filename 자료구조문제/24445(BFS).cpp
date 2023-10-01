#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, r;
vector<int>mat[100001];
bool visited[100001] = { 0 };
int res[100001] = { 0 };
int idx = 1;

bool com(int i, int j) {
	return i > j;
}

void bfs(int start) {
	queue<int>q;
	visited[start] = 1;
	res[start] = idx++;
	q.push(start);
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		for (int i = 0; i < mat[next].size(); i++) {
			if (!visited[mat[next][i]]) {
				q.push(mat[next][i]);
				visited[mat[next][i]] = 1;
				res[mat[next][i]] = idx++;
			}
		}
	}
}

int main()
{
	int a, b;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) 
		sort(mat[i].begin(), mat[i].end(), com);
	
	bfs(r);
	for (int i = 1; i <= n; i++) 
		cout << res[i] << '\n';
}