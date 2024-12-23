#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
unordered_set<ll>s;

void solve() {
    s.insert(n);
    queue<pair<ll, ll>>q;
    q.push({ n,0 });
    while (q.size()) {
        auto [x, c] = q.front();
        q.pop();
        if (x == 1) {
            cout << c;
            return;
        }
        if (x % 3 == 0 && s.find(x / 3) == s.end()) {
            q.push({ x / 3,c + 1 });
            s.insert(x / 3);
        }
        if (x % 2 == 0 && s.find(x / 2) == s.end()) {
            q.push({ x / 2,c + 1 });
            s.insert(x / 2);
        }
        if (s.find(x - 1) == s.end()) {
            q.push({ x - 1,c + 1 });
            s.insert(x - 1);
        }
    }
}

void input() {
    cin >> n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}