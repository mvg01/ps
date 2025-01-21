#include <bits/stdc++.h>
using namespace std;

int n, m, p[1001], ans = 0;
char c[1001];
vector<tuple<int, int, int>>v;

void init() {
    for (int i = 1; i < 1001; i++) p[i] = i;
}

int getParent(int x) {
    if (x == p[x])
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
    int cnt = 0;
    sort(v.begin(), v.end());  // 간선 정렬
    init();
    for (int i = 0; i < v.size(); i++) {
        int w = get<0>(v[i]);
        int a = get<1>(v[i]);
        int b = get<2>(v[i]);
        if (getParent(a) != getParent(b)) {  // 사이클 생성 가능
            ans += w;
            setUnion(a, b);
            cnt++;
        }
        if (cnt == n-1) {
            cout << ans;
            return;
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        if (c[a] != c[b])  // 양방향 간선이지만 분리집합 개념이므로 간선 하나만 연결해둠!
            v.push_back({ w,a,b });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}