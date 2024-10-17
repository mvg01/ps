#include <bits/stdc++.h>
using namespace std;

int n, cnt = 1;
string a, b, c;
bool vis[201][201];

void solve() {
    int al = a.length(), bl = b.length(), cl = c.length();
    queue<tuple<int, int, int> > q;
    if (c[0] == a[0]) {
        q.push({1, 0, 1});
        vis[1][0] = 1;
    }
    if (c[0] == b[0]) {
        q.push({0, 1, 1});
        vis[0][1] = 1;
    }
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < 201; j++)
            vis[i][j] = 0;
    }

    while (!q.empty()) {
        int a1 = get<0>(q.front());
        int b1 = get<1>(q.front());
        int idx = get<2>(q.front());
        q.pop();
        if (cl == idx) {
            cout << "Data set " << cnt++ << ": yes\n";
            return;
        }
        if (a1 != al) {
            if (c[idx] == a[a1] && !vis[a1 + 1][b1]) {
                q.push({a1 + 1, b1, idx + 1});
                vis[a1 + 1][b1] = 1;
            }
        }
        if (b1 != bl) {
            if (c[idx] == b[b1] && !vis[a1][b1 + 1]) {
                q.push({a1, b1 + 1, idx + 1});
                vis[a1][b1 + 1] = 1;
            }
        }
    }
    cout << "Data set " << cnt++ << ": no\n";
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}
