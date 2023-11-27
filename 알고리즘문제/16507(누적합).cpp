#include <iostream>
using namespace std;

int r, c, q;
int sum[1001][1001] = { 0 };

void input() {
	int x;
	cin >> r >> c >> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> x;
			if (j == 0)
				sum[i][j] = x;
			else
				sum[i][j] = sum[i][j - 1] + x;
		}
	}
}

void solve() {
	int a, b, x, y, res;
	for (int i = 0; i < q; i++) {
		res = 0;
		cin >> a >> b >> x >> y;
		for (int j = a-1; j <= x-1; j++) {
			res += sum[j][y - 1] - sum[j][b - 2];
		}
		//cout << res << '\n';
		cout << res / ((x - a + 1) * (y - b + 1)) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}