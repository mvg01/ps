#include <iostream>
#include <queue>
using namespace std;

int n, mx = -9999, mn = 9999;
char mat[6][6];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

void dfs(int y,int x,char prev,int temp) {
	if (y == n-1 && x == n-1) {
		switch (prev) {
		case '+':
			temp += mat[y][x] - '0';
			break;
		case '-':
			temp -= mat[y][x] - '0';
			break;
		case '*':
			temp *= mat[y][x] - '0';
			break;
		}
		mx = max(mx, temp);
		mn = min(mn, temp);
		return;
	}

	switch (prev) {
	case '+':
		temp += mat[y][x] - '0';
		break;
	case '-':
		temp -= mat[y][x] - '0';
		break;
	case '*':
		temp *= mat[y][x] - '0';
		break;
	}
	if (y + 1 < n)
		dfs(y + 1, x, mat[y][x], temp);
	if (x + 1 < n)
		dfs(y, x + 1, mat[y][x], temp);
}

void solve() {
	int num = mat[0][0] - '0';  //초기 숫자
	dfs(0, 0, mat[0][0], num);
	cout << mx << ' ' << mn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}