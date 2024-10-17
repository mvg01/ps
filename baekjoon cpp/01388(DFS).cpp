#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int visited[51][51];
char mat[51][51];

void dfs1(int a, int b) {
	if (mat[a][b] == '-') {
		for (int i = b + 1; i < m; i++) {
			if (mat[a][i] == '-' && visited[a][i] == 0) {
				visited[a][i] = 1;
				dfs1(a, i);
			}
			else
				break;
		}
	}
}

void dfs2(int a, int b) {
	if (mat[a][b] == '|') {
		for (int i = a + 1; i < n; i++) {
			if (mat[i][b] == '|' && visited[i][b] == 0) {
				visited[i][b] = 1;
				dfs2(i, b);
			}
			else
				break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			mat[i][j] = x;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '-')
				dfs1(i, j);
			else if (mat[i][j] == '|')
				dfs2(i, j);

			if (visited[i][j] == 0) {
				visited[i][j] = 1;
				res++;
			}
		}
	}
	cout << res;
}