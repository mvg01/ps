#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int mat[101][101];
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
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			mat[i][j] = 999999999;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	floyd(n);
	int res = 0;
	for (int i = 2; i <=n; i++) {
		if (mat[1][i] != 999999999)  //만약 연결된 적이 없다면
			res++;
	}
	cout << res;
}