#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[300001];
void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void solve() {
    long long res = 0;
    int idx = 0, temp = 0;
    sort(a, a + n);
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) 
            res += a[n - 1 - i / 2] - temp;
        else
            temp = a[idx++];
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}