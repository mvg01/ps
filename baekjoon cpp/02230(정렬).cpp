#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    sort(a, a + n);
    int r = 0, ans = 2000000001;
    for (int i = 0; i < n; i++) {
        if (a[r] - a[i] >= m) {
            ans = min(ans, a[r] - a[i]);
        } else {
            if (r != n) {
                i--;
                r++;
            }
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