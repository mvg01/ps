#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, c, idx = 1, p[21];
vector<pair<int, pair<int, int>>>v;

void init() {
    for (int i = 1; i <= 21; i++) p[i] = i;
}

int getParent(int x) {
    if (x == p[x]) return x;
    else return p[x] = getParent(p[x]);
}

void setUnion(int a, int b) {
    int aa = getParent(a);
    int bb = getParent(b);
    if (aa < bb)
        p[aa] = bb;
    else
        p[bb] = aa;
}

void solve() {
    init();
    sort(v.begin(), v.end());
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        if (getParent(a) != getParent(b)) {
            setUnion(a, b);
            ans += v[i].first;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    cout << "Case #" << idx++ << ": " << ans << " meters\n";
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            v.push_back({ c,{a,b} });
        }
        solve();
        v.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}