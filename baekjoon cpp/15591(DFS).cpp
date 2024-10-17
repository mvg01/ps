#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<pair<int, int>>mat[5001];
int usado[5001][5001];
int visited[5001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        mat[a].push_back({ b,c });
        mat[b].push_back({ a,c });
    }
}

void dfs(int s, int v, int mn) {
    for (int i = 0; i < mat[v].size(); i++) {
        if (!visited[mat[v][i].first]) {
            visited[mat[v][i].first] = 1;
            usado[s][mat[v][i].first] = min(mn, mat[v][i].second);
            dfs(s, mat[v][i].first, min(mn, mat[v][i].second));
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++)
        visited[i] = 0;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        init();
        usado[i][i] = 0;
        visited[i] = 1;
        dfs(i, i, 1000000000);
    }
    // 질문 쿼리
    for (int i = 0; i < m; i++) {  
        int ki, vi, res = 0;
        cin >> ki >> vi;
        for (int j = 1; j <= n; j++) {
            if (usado[vi][j] >= ki)
                res++;
        }
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}