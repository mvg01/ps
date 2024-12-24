#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9, a[100001];
void solve() {
    sort(a, a + n);
    for (int i = 0; i < n / 2; i++) 
        ans = min(a[i] + a[n - i - 1], ans);
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}