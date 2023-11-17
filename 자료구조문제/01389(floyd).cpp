#include <iostream>
#define INF 999999999
using namespace std;

int mat[101][101];
int n, m;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = INF;
		}
	}
}

void floyd() {
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int solve() {
	int res = 0, minsum = INF;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j++) {
			temp += mat[i][j];
		}
		if (minsum > temp) {
			res = i + 1;
			minsum = temp;
		}
	}
	return res;
}

int main()
{
	int a, b;
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	floyd();
	cout << solve();
}