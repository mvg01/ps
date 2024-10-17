#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> adj_mat;
vector<int> visited;
vector<int> res;

void init()
{
	adj_mat.resize(n + 1);
	visited.resize(n + 1);
	res.resize(n + 1);

	for (int i = 0; i <= n; i++)
		visited[i] = 0;
	for (int i = 0; i <= n; i++)
		res[i] = 0;
}

void insert(int start, int end)
{
	adj_mat[start].push_back(end);
	adj_mat[end].push_back(start);
}

int idx = 1;
void dfs(int v)
{
	int w;
	visited[v] = 1;
	//cout << v << '\n';
	res[v] = idx++;

	for (int i = 0; i < adj_mat[v].size(); i++)
	{
		w = adj_mat[v][i];
		if (visited[w] == 0)
			dfs(w);
	}
}

//void print()
//{
//	for (int i = 1; i <= n; i++) {
//		for (int j = 0; j < adj_mat[i].size(); j++) {
//			cout << adj_mat[i][j] << ' ';
//		}
//		cout << "\n";
//	}
//}

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
	for (int i = 1; i <= n; i++) {
		sort(adj_mat[i].begin(), adj_mat[i].end());
	}
	//print();
	dfs(r);

	for (int i = 1; i <= n; i++) 
		cout << res[i] << '\n';
}