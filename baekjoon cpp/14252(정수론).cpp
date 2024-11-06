#include <bits/stdc++.h>
using namespace std;

int n, a;
vector<int>v;

int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solve() {
	int cnt = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		int g = gcd(v[i], v[i + 1]);
		bool chk = 0;
		if (g > 1) {
			// 이웃한 두 수 사이에서 한 개의 최대공약수를 만들어 줄 수 있는지 체크
			for (int j = v[i]; j <= v[i + 1] - 1; j++) {
				if (gcd(v[i], j) == 1 && gcd(j, v[i + 1]) == 1) {  // 한 개의 최대공약수 가능
					v.insert(v.begin() + i + 1, j); 
					cnt++;
					chk = 1;
					break;
				}
			}
			if (!chk) // 최대공약수가 1개가 될 수 없다면 무조건 2개 필요
				cnt += 2;
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
}