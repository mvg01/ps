#include <bits/stdc++.h>
using namespace std;

int n, idx = 1;
vector<tuple<int, int>>mat[501];
vector<tuple<int, int, int>>e;
vector<pair<int, int>>v;
int parent[501];

bool c(tuple<int, int>a, tuple<int, int>b) {
    return get<1>(a) < get<1>(b);
}

void init() {
    v.clear();
    e.clear();
    for (int i = 0; i < 501; i++) {
        parent[i] = i;
        mat[i].clear();
    }
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}

void setUnion(int a, int b) {
    int aa = getParent(a);
    int bb = getParent(b);
    if (aa > bb)
        parent[aa] = bb;
    else
        parent[bb] = aa;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                int dis = pow(v[i-1].first - v[j-1].first, 2) + pow(v[i-1].second - v[j-1].second, 2);
                mat[i].push_back({ j,dis });
            }
        }
    }
    for (int i = 1; i <= n; i++)
        sort(mat[i].begin(), mat[i].end(), c);

    for (int i = 1; i <= n; i++) {
        if (!mat[i].empty()) {
            int d = get<1>(mat[i][0]);
            e.push_back({ i,get<0>(mat[i][0]),get<1>(mat[i][0]) });
            for (int j = 1; j < mat[i].size(); j++) {
                if (get<1>(mat[i][j]) == d)
                    e.push_back({ i,get<0>(mat[i][j]),get<1>(mat[i][j]) });
                else
                    break;
            }
        }
    }
    for (int i = 0; i < e.size(); i++) {
        auto [x, y, dis] = e[i];
        setUnion(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == getParent(i))
            cnt++;
    }
    cout << "Sky " << idx++ << " contains " << cnt << " constellations.\n";
}

void input() {
    double a, b;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        init();
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back({ a,b });
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}