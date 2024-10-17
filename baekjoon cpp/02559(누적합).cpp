#include <iostream>
using namespace std;

int n, k, a[1000001];
int sum[1000001] = { 0 };

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
}

void solve() {
    int res = -10000000;
    for (int i = k; i <= n; i++)
        res = max(res, sum[i] - sum[i - k]);
    
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}