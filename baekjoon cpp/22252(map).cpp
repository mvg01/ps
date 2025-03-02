#include <bits/stdc++.h>
using namespace std;

int q, k, c, n;
long long ans = 0;
unordered_map<string, multiset<int>>m;

void input() {
    cin >> q;
    for (int i = 0; i < q; i++) {
        string na;
        cin >> k >> na >> c;
        if (k == 1) {
            for (int j = 0; j < c; j++) {
                cin >> n;
                m[na].insert(n);
            }
        }
        else {
            if (m.find(na) == m.end())
                continue;
            for (int j = 0; j < c; j++) {
                if (m[na].empty())
                    break;
                auto it = m[na].end();
                --it;
                ans += *it;
                m[na].erase(it);

            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}