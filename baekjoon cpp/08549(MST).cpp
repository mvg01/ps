#include <bits/stdc++.h>
using namespace std;

int n, m, p[100001];
vector<tuple<int, int, int>>v;

void init() {
    for (int i = 1; i <= n; i++)
        p[i] = i;
}

int getParent(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = getParent(p[x]);
}

void setUnion(int a, int b) {
    int aa = getParent(a);
    int bb = getParent(b);
    if (aa > bb)
        p[aa] = bb;
    else
        p[bb] = aa;
}

void solve() {
    int cnt = 0, mx = 0;
    init();
    sort(v.begin(), v.end());
    for (auto i:v) {
        if (getParent(get<1>(i)) != getParent(get<2>(i))) {
            setUnion(get<1>(i), get<2>(i));
            cnt++;
            mx = max(mx, get<0>(i));
        }
        if (cnt == n - 1)
            break;
    }
    cout << mx;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ c,a,b });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}