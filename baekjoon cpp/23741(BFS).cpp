#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<int>mat[1001];
int visited[1001][1001];

void input() {
    int a, b;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
}

void solve() {
    if (mat[x].empty()) {
        cout << -1;
        return;
    }
    queue<pair<int, int>>q;
    q.push({ 0,x });
    visited[0][x] = 1;
    while (!q.empty()) {
        int c, v;
        tie(c, v) = q.front();
        q.pop();
        if (c == y) 
            continue;
        for (int i = 0; i < mat[v].size(); i++) {
            int next = mat[v][i];
            if (visited[c + 1][next])
                continue;
            q.push({ c + 1,next });
            visited[c + 1][next] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (visited[y][i])
            cout << i << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}


// dp 활용 풀이 bfs와 크게 다를 건 없다..

#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
vector<int>mat[1001];
bool visited[1001][1001];

void input() {
    int a, b;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
}

void f(int a, int b) {
    for (int i = 0; i < mat[b].size(); i++) 
        visited[a][mat[b][i]] = 1;
}

void solve() {
    if (mat[x].empty()) {
        cout << -1;
        return;
    }
    visited[0][x] = 1;
    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= n; j++) {
            if (visited[i - 1][j])
                f(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
        if (visited[y][i]) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}