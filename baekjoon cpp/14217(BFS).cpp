#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, q, a, x, y;
int dis[501];
vector<int>v[501];
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin >> q;
}

void bfs() {
    for (int i = 1; i <= n; i++)
        dis[i] = -1;
    queue<int>q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty()) {
        int ver = q.front();
        int d = dis[ver];
        q.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int e = v[ver][i];
            if (dis[e] != -1)
                continue;
            q.push(e);
            dis[e] = d + 1;
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << '\n';
}

void solve() {
    while (q--) {
        cin >> a >> x >> y;
        if (a == 2) {
            for (int i = 0; i < v[x].size(); i++) {
                if (v[x][i] == y)
                    v[x].erase(v[x].begin() + i);
            }
            for (int i = 0; i < v[y].size(); i++) {
                if (v[y][i] == x)
                    v[y].erase(v[y].begin() + i);
            }
            bfs();
        }
        else {
            v[x].push_back(y);
            v[y].push_back(x);
            bfs();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}