#include <bits/stdc++.h>
using namespace std;

int n, q, x, c, v;
set<int>s;

void input() {
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++)
        cin >> x;
    for (int i = 0; i < q; i++) {
        cin >> c >> v;
        if (c == 1) 
            s.insert(v);
        else {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            auto it = s.lower_bound(v);
            int ans;
            if (it == s.end()) {
                it--;
                ans = v - *it;
            }
            else {
                ans = *it - v;
                if (it != s.begin()) {
                    it--;
                    ans = min(ans, v - *it);
                }
            }
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}