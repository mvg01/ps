#include <bits/stdc++.h>
using namespace std;

int n, m, k, res = 0;
int v[21];
int a[101][11];

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++)
            cin >> a[i][j];
    }
}

void f(int cnt, int s) {
    if (cnt == n) {
        int c = 0;
        for (int i = 0; i < m; i++) {
            bool chk = 0;
            for (int j = 0; j < k; j++) {
                if (!v[a[i][j]]) {
                    chk = 1;
                    break;
                }
            }
            if (!chk)
                c++;
        }
        res = max(res, c);
        return;
    }
    //최대 20 C 10 의 조합 백트래킹
    for (int i = s; i <= (2 * n); i++) {
        if (!v[i]) {
            v[i] = 1; 
            f(cnt + 1, i + 1);
            v[i] = 0;
        }
    }
}

void solve() {
    f(0, 1);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}