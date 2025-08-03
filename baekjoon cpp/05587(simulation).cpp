#include <bits/stdc++.h>
using namespace std;

int n, x[201];
vector<int>a, b;
bool chk = 1;  // 상근이 턴

void solve() {
    for (int i = 1; i <= n * 2; i++) {
        if (x[i]) a.push_back(i);
        else b.push_back(i);
    }
    int c = a[0];
    a.erase(a.begin());
    while (a.size() && b.size()) {
        if (chk) {
            for (int i = 0; i < b.size(); i++) {
                if (c < b[i]) {
                    c = b[i];
                    b.erase(b.begin() + i);
                    chk = 0;
                    break;
                }
            }
            if (chk) {
                c = a[0];
                a.erase(a.begin());
            }
        }
        else {
            for (int i = 0; i < a.size(); i++) {
                if (c < a[i]) {
                    c = a[i];
                    a.erase(a.begin() + i);
                    chk = 1;
                    break;
                }
            }
            if (!chk) {
                c = b[0];
                b.erase(b.begin());
            }
        }
    }
    cout << b.size() << ' ' << a.size();
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        x[y] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}