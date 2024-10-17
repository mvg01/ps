#include <bits/stdc++.h>
using namespace std;

int n, u, v, a, b, c;
vector<int>mat[200001];
int visited[200001][3];

void input() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u);
    }
    cin >> a >> b >> c;
}

void bfs(int s, int w) {
    queue<int>q;
    q.push(s);
    visited[s][w] = 1;
    while (!q.empty()) {
        int ver = q.front();
        int d = visited[ver][w];
        q.pop();
        for (int i = 0; i < mat[ver].size(); i++) {
            if (visited[mat[ver][i]][w])
                continue;
            q.push(mat[ver][i]);
            visited[mat[ver][i]][w] = d + 1;
        }
    }
}

void solve() {
    bfs(a, 0);
    bfs(b, 1);
    bfs(c, 2);
    bool chk = 0;
    for (int i = 1; i <= n; i++) {
        if (mat[i].size() == 1) {
            if (visited[i][0] < visited[i][1] && visited[i][0] < visited[i][2])
                chk = 1;
        }
    }
    if (chk)
        cout << "YES";
    else
        cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}