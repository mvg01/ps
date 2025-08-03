#include <iostream>
using namespace std;

int n, a[1000001], chk[11];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    int l = 0, r = 0, ans = 1;
    chk[a[l]]++;
    while (1) {
        if (r == n)
            break;
        int mn = 11, mx = 0;
        for (int i = 1; i <= 10; i++) {
            if (chk[i] > 0) {
                mn = min(mn, i);
                mx = max(mx, i);
            }
        }
        if (mx - mn <= 2) {
            chk[a[++r]]++;
            ans = max(ans, r - l);
        }
        else {
            chk[a[l]]--;
            l++;
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