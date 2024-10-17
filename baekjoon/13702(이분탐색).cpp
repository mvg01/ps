#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, res = 0;
int a[10001];

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
}

void solve() {
	long left = 0, right = a[n - 1], mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mid != 0)
				cnt += a[i] / mid;
			else
				continue;
		}
		if (cnt >= k)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	if (k == 1)
		cout << a[0];
	else
		cout << right;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}