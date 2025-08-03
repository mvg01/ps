#include <iostream>
#include <vector>
using namespace std;

int n, k;
int a[200001];
int cnt[100001] = { 0 };

void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve() {
	int idx = 0, res = 0, len = 0;
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
		len++;
		if (cnt[a[i]] > k) {
			for (; ; idx++) {
				cnt[a[idx]]--;
				len--;
				if (a[i] == a[idx])
					break;
			}
			idx++;
		}
		res = max(res, len);
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}