#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

void solve() {
    int cnt = n - k + 1;
    for (int i = k - 1; i < n; i++)
        cout << s[i];
    if (cnt % 2 == 1) {
        for (int i = k - 2; i >= 0; i--)
            cout << s[i];
    }
    else {
        for (int i = 0; i < k - 1; i++)
            cout << s[i];
    }
}

void input() {
    cin >> n >> k >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}