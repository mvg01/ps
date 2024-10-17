#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int mat[101][101];

void floyd(int n) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		mat[a][b] = min(mat[a][b], c);  //중복된 출발과 도착이 있을 때 최소 비용으로
	}

	floyd(n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
}