#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
bool c(int i, int j) {
    return i > j;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    sort(a, a + n, c);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i] + a[i + 1];
        int temp = max(a[i], a[i + 1]);
        a[i + 1] = temp;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}