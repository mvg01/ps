#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, a[2001];

void solve() {
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] + a[r] == a[i]) {
                if (l == i) l++;
                else if (r == i) r--;
                else {
                    ans++;
                    break;
                }
            }
            else if (a[l] + a[r] > a[i]) r--;
            else l++;
        }
    }
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