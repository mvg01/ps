#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, k, a, b, c, mid, ans2 = 0;
int p[1001];
vector<tuple<int, int, int>>mat;
vector<pair<int, int>>v[1001];
bool vis[1001];

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

void dfs(int node, int sum) {
    if (vis[node])
        return;
    vis[node] = 1;
    if (ans2 < sum) {
        ans2 = sum;
        mid = node;
    }
    for (auto i : v[node])
        dfs(i.first, sum + i.second);
}

void solve() {
    for (int i = 0; i < 1001; i++) p[i] = i;
    sort(mat.begin(), mat.end());
    int cnt = 0, ans1 = 0, mn = 1e9;
    for (auto i : mat) {
        int c = get<0>(i);
        int a = get<1>(i);
        int b = get<2>(i);
        if (getParent(a) != getParent(b)) {
            setUnion(a, b);
            cnt++;
            ans1 += c;
            v[a].push_back({ b,c });
            v[b].push_back({ a,c });
            if (cnt == n - 1)
                break;
        }
    }
    cout << ans1 << '\n';
    // ans2 연결된 도시들로 트리의 지름 길이
    dfs(0, 0);
    memset(vis, 0, sizeof(vis));
    ans2 = 0;
    dfs(mid, 0);
    cout << ans2;
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        mat.push_back({ c,a,b });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}