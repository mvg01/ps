#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int n;
int mat[51][51];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				mat[i][j] = INF;
			else
				mat[i][j] = 0;
		}
	}
}

void input() {
	int a, b;
	cin >> n;
	init();
	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

void solve() {
	floyd();
	int score = n;
	vector<int>res;
	for (int i = 1; i <= n; i++) {
		int c = 0;
		for (int j = 1; j <= n; j++) {
			c = max(c, mat[i][j]);  //각 정점으로부터 가장 큰 거리가 친구 점수, 모두 1이면 1점
		}
		if (c < score) {
			score = c;
			res.clear();
			res.push_back(i);
		}
		else if (c == score)
			res.push_back(i);
	}
	cout << score << ' ' << res.size() << '\n';
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}