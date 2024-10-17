#include <iostream>
#include <vector>
using namespace std;

int n, s, res;
int a[100001];
int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

void input() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < s)
			a[i] = s - a[i];
		else
			a[i] = a[i] - s;
	}
}

void solve() {
	if (n == 1) {
		cout << a[0];
		return;
	}

	res = gcd(a[0], a[1]);
	for (int i = 1; i < n; i++) 
		res = gcd(res, a[i]);
	
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}