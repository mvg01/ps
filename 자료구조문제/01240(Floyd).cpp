#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mat[1001][1001];
void floyd(int n) {
	for (int k = 0; k <= n; k++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++)
			mat[i][j] = 999999999;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		mat[a][b] = c;
		mat[b][a] = c;
	}

	floyd(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << mat[a][b] << '\n';
	}
}