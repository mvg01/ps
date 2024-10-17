#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[1000001];
void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    sort(a, a + n);
    long long ans = 0;
    long long start = a[0], mid, end = a[n - 1] + k;
    while (start <= end) {
        mid = (start + end) / 2;
        long long t = 0;
        bool chk = 0;
        for (int i = 0; i < n; i++) {
            if (mid > a[i]) {
                t += mid - a[i];
                if (t > k) {
                    chk = 1;
                    break;
                }
            }
        }
        if (!chk) {
            ans = max(ans, mid);
            start = mid + 1;
        }
        else {
            end = mid - 1;
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