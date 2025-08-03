#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int mat[401][401];
int v, e;
int res = INF;

void input() {
	int a, b, c;
	cin >> v >> e;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i != j)
				mat[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		a--; b--;
		mat[a][b] = c;
	}
}

void floyd() {
	for (int k = 0; k < v; k++) {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int chk(int s) {
	int dis = INF;
	for (int i = 0; i < v; i++) {
		if (s == i)
			continue;
		if (mat[s][i] != INF && mat[i][s] != INF)  //사이클 존재
			dis = min(dis, mat[s][i] + mat[i][s]);
	}
	return dis;
}

void solve() {
	floyd();
	for (int i = 0; i < v; i++) 
		res = min(res, chk(i));
	
	if (res != INF)
		cout << res;
	else
		cout << -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}