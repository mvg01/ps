#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, cnt = 0;
ll a[200001], sum[200001], ans = -1;
map<ll, int>m;
map<ll, int>m2;

void solve() {
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        if (m.find(a[i]) == m.end())
            m.insert({ a[i],i });
        else
            m2[a[i]] = i;
    }
    for (auto& p : m) {
        int firstIdx = p.second, secondIdx = -1;
        if (m2.find(p.first) != m2.end())
            secondIdx = m2[p.first];
        if (secondIdx == -1) {
            if (ans < a[p.second]) {
                cnt = 1;
                ans = a[p.second];
            }
            else if (ans == a[p.second]) 
                cnt++;
        }
        else {
            if (ans < sum[secondIdx] - sum[firstIdx - 1]) {
                cnt = 1;
                ans = sum[secondIdx] - sum[firstIdx - 1];
            }
            else if (ans == sum[secondIdx] - sum[firstIdx - 1])
                cnt++;
        }
    }
    cout << ans << ' ' << cnt;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}