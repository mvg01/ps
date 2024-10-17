#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int n, k;
ll a[300001], res = 0;
ll sum[300001] = { 0 };

void input() {
	cin >> n >> k;
}

void solve() {  
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	int cnt = 0;

	sum[0] = a[0];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + a[i];

	for (int i = 0; i < n; i++) {
		if (cnt < k) {
			res += sum[n - 1] - sum[i];
			cnt++;
		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}