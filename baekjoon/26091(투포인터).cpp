#include <bits/stdc++.h>
using namespace std;

int n, m, a[100001];
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void solve() {
    sort(a, a + n);
    int s = 0, e = n - 1, res = 0;
    while (s < e) {
        if (a[s] + a[e] >= m) {
            s++; e--;
            res++;
        }
        else
            s++;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}