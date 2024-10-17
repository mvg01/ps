#include <iostream>
using namespace std;

int n, q, x, y;
int a[100001];
int sum[100001] = { 0 };

void input() {
	cin >> n;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];

		if (a[i - 1] > a[i])
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1];
	}
	cin >> q;
}
void solve() {
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		x--; y--;
		cout << sum[y] - sum[x] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}