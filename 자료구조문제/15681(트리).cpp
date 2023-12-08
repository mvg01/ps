#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<int>mat[100001];
int visited[100001] = { 0 };

void input() {
	int a, b;
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
}
void dfs(int cur, int par) {
	int size = mat[cur].size();
	visited[cur] = 1;
	for (int i = 0; i < size; i++) {
		if (mat[cur][i] != par) { 
			dfs(mat[cur][i], cur);
			visited[cur] += visited[mat[cur][i]];
		}
	}
}


void solve() {
	dfs(r, -1); // r이 루트노드, 부모노드는 없다.
	int u;
	for (int i = 0; i < q; i++) {
		cin >> u;
		cout << visited[u] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}