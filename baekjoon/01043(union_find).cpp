#include <iostream>
#include <vector>
using namespace std;

int n, m, s;
int parent[51];
vector<int>p[51];

int getParent(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = getParent(parent[x]);  // 효율적인 경로 압축
}

void set_union(int x, int y) {
    int r1 = getParent(x);
    int r2 = getParent(y);
    if (r1 < r2)
        parent[r2] = r1;
    else
        parent[r1] = r2;
}

void input() {
    int x, z, y;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < s; i++) {
        cin >> x;
        parent[x] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        cin >> z;
        p[i].push_back(z);
        for (int j = 1; j < x; j++) {
            cin >> y;
            set_union(z, y);
            z = y;
            p[i].push_back(y);
        }
    }
}

void solve() {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool chk = 0;
        for (int j = 0; j < p[i].size(); j++) {
            if (getParent(p[i][j]) == 0)
                chk = 1;
        }
        if (!chk)
            ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}