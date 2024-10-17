#include <iostream>
using namespace std;

int n, a[1001], dp[1001];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}