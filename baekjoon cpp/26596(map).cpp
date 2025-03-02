#include <bits/stdc++.h>
#define G 1.618
using namespace std;

int n, x;
string s;
unordered_map<string, int>m;

void solve() {
    for (auto i : m) {
        for (auto j : m) {
            if (i.first == j.first)
                continue;
            if ((int)(i.second * G) == j.second) {
                cout << "Delicious!";
                return;
            }
        }
    }
    cout << "Not Delicious...";
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> x;
        m[s] += x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}