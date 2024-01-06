#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, res = 0;
vector<int>a;
vector<int>b;
long long d;

void input() {
	int x, y;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x == 1)
			a.push_back(y);
		else
			b.push_back(y);
	}
}
void solve() {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int idx1 = 0, idx2 = 0;
	int limit1 = a.size(), limit2 = b.size();
	while (1) {
		if (idx1 == limit1) {
			res += limit2 - idx2;
			break;
		}
		if (d > a[idx1]) {
			d += a[idx1];
			idx1++;
		}
		else {
			if (idx2 == limit2)
				break;
			d *= b[idx2];
			idx2++;
		}
		res++;
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}