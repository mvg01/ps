#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, b, a;
ll v[100001], sum[100001];

void solve() {
    sort(v, v + n);
    sum[0] = v[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + v[i];
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (n - i - a - 1 < 0) {
            ll temp = sum[n - i - 1] / 2;
            if (b >= temp)
                break;
            else {
                ans--;
                continue;
            }
        }
        ll temp = sum[n - i - 1] - sum[n - i - a - 1];
        temp /= 2;
        if (b >= sum[n - i - a - 1] + temp)
            break;
        ans--;
    }
    cout << ans;
}

void input() {
    cin >> n >> b >> a;
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}