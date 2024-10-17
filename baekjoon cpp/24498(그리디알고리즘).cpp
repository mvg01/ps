#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];
}

void solve() {
    int res = max(a[0], a[n - 1]);
    for (int i = 1; i < n - 1; i++) {
        int y = min(a[i - 1], a[i + 1]);
        res = max(res, a[i] + y);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}