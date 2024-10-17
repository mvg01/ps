#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int n, m, ans = 1000000000;
int a[100001];
void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    int start = *max_element(a, a + n), end = 1000000000, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        int cnt = 1, temp = mid;
        for (int i = 0; i < n; i++) {
            if (temp >= a[i]) 
                temp -= a[i];
            else {
                cnt++;
                temp = mid;
                temp -= a[i];
            }
        }
        if (cnt > m)
            start = mid + 1;
        else {
            ans = min(ans, mid);
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