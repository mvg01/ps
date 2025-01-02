#include <bits/stdc++.h>
using namespace std;

int n, a[1001];
void solve() {
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        int cnt = 1, temp = -1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                cnt++;
            else if (temp == -1)
                temp = a[j];
            else if (temp == a[j])
                continue;
            else
                break;
        }
        ans = max(ans, cnt);
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