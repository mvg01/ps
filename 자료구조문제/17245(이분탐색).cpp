#include <iostream>
#define ll long long
using namespace std;

int n;
ll mat[1001][1001];
ll sum = 0, mx = 0, res = 0;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            sum += mat[i][j];
            mx = max(mx, mat[i][j]);
        }
    }
}

void solve() {
    ll left = 0, right = mx, mid;
    sum = (sum % 2) ? sum / 2 + 1 : sum / 2;
    while (left <= right) {
        mid = (left + right) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mid < mat[i][j])
                    cnt += mid;
                else
                    cnt += mat[i][j];
            }
        }
        if (cnt >= sum) {
            res = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}