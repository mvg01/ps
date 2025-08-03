#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
ll x[1000001];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
}

void solve() {
    ll left = 0, right = 1000000000, mid, ans = 1000000000;
    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = 0;
        bool pre = 0;
        for (int i = 1; i < n; i++) {
            if (abs(x[i] - x[i - 1]) > mid) {
                cnt++;
                if (!pre)
                    cnt++;
                pre = 1;
            } else
                pre = 0;
        }
        if (cnt <= k) {
            ans = min(ans, mid);
            right = mid - 1;
        } else if (cnt > k) {
            left = mid + 1;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}