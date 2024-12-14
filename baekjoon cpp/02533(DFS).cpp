#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> t[1000001];
bool vis[1000001];

bool dfs(int v) {
    vis[v] = 1;
    bool early = 0;
    for (int i = 0; i < t[v].size(); i++) {
        if (!vis[t[v][i]]) {
            // 자식 노드 중 하나라도 early가 아니라면 부모가 early가 되..
            if (!dfs(t[v][i]))  
                early = 1;
        }
    }
    if (!early) return 0;
    else {
        ans++;
        return 1;
    }
}
void input() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    dfs(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}