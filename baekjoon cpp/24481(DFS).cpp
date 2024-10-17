#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> visited;
vector <int> res;
vector<vector<int>>mat;
void init() {
	visited.resize(n + 1);
	mat.resize(n + 1);
	res.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		visited[i] = 0;
		res[i] = 0;
	}
}
void insert(int s,int e) {
	mat[s].push_back(e);
	mat[e].push_back(s);
}

int idx = 1;
void dfs(int v, int depth) {
	int w;
	visited[v] = 1;
	res[v] = depth;
	for (int i = 0; i < mat[v].size(); i++) {
		w = mat[v][i];
		if (visited[w] == 0) {
			dfs(w, depth + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, r, a, b;
	cin >> n >> m >> r;
	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		insert(a, b);
	}
	for (int i = 1; i <= n; i++)
		sort(mat[i].begin(), mat[i].end());
	
	dfs(r, 0);

	for (int i = 1; i <= n; i++) {
		if (i == r)
			cout << 0 << '\n';
		else if (res[i] == 0)
			cout << -1 << '\n';
		else
			cout << res[i] << '\n';
	}	
}