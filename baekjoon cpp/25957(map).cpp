#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, string>um;

void solve() {
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s.length() > 3)
            sort(s.begin() + 1, s.end() - 1);
        cout << um[s] << ' ';
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, ori;
        cin >> s;
        ori = s;
        if (s.length() > 3)
            sort(s.begin() + 1, s.end() - 1);
        um[s] = ori;
    }
    cin >> m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}