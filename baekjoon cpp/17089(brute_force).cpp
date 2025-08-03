#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 1e9;
vector<int> mat[4001];
set<pair<int, int> > s;

void solve() {
    for (int i = 1; i <= n; i++) {
        if (mat[i].size() < 2)
            continue;
        for (int j = 0; j < mat[i].size() - 1; j++) {
            int x = mat[i][j];
            for (int k = j + 1; k < mat[i].size(); k++) {
                int y = mat[i][k];
                if (s.find({x, y}) != s.end()) {
                    int temp = mat[i].size() + mat[x].size() + mat[y].size();
                    ans = min(ans, temp - 6);
                }
            }
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
        s.insert({a, b});
        s.insert({b, a});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}