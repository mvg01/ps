#include <bits/stdc++.h>
using namespace std;

int n, t, k;
unordered_map<string, string>m;

void solve() {
    while (t--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            cout << m[s] << ' ';
        }
        cout << '\n';
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        m[a] = c;
    }
    cin >> t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}