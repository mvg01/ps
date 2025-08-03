#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, t;
vector<ll>bit;
void solve() {
    for (int i = 0; i < m; i++) {
        cin >> t;
        ll x, bm = 0, ans = 0;
        for (int j = 0; j < t; j++) {
            cin >> x;
            bm |= ((ll)1 << (x - 1));
        }
        for (int j = 0; j < n; j++) {
            if ((bit[j] & bm) == bit[j])
                ans++;
        }
        cout << ans << '\n';
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ll x, bm = 0;
        for (int j = 0; j < t; j++) {
            cin >> x;
            bm |= ((ll)1 << (x - 1));  // 1을 x-1 위치로 or 연산
        }
        bit.push_back(bm);
    }
    cin >> m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}