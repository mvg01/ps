#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

int n, p[11], ans = 1000000;
bool visited[11];
vector<int>v[11];

void input() {
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            v[i].push_back(y);
            v[y].push_back(i);
        }
    }
}

int connect(vector<int>g, bool rev) {
    int cnt = 1;
    bool vv[11] = { 0 };
    vv[g[0]] = 1;
    queue<int>q;
    q.push(g[0]);

    while (!q.empty()) {
        int point = q.front();
        q.pop();
        for (int i = 0; i < v[point].size(); i++) {
            if (vv[v[point][i]])
                continue;
            if (rev) {
                if (visited[v[point][i]])
                    continue;
            }
            else {
                if (!visited[v[point][i]])
                    continue;
            }
            vv[v[point][i]] = 1;
            q.push(v[point][i]);
            cnt++;
        }
        if (cnt == g.size())
            return 1;
    }
    return 0;
}

void dfs(int start, int depth) {
    if (depth == n) {
        return;
    }
    else if (depth != 0) {
        bool chk = 0;
        vector<int>a;
        vector<int>b;
        for (int i = 1; i <= n; i++) {
            if (visited[i])
                a.push_back(i);
            else
                b.push_back(i);
        }
        if (!connect(a, false))  // 방문처리가 되어있는 애들끼리 연결된건지
            chk = 1;
        if (!connect(b, true))  // 방문처리가 안되어있는 애들끼리 연결된건지
            chk = 1;

        if (!chk) {
            int a1 = 0, b1 = 0;
            for (int i = 1; i <= n; i++) {
                if (visited[i])
                    a1 += p[i];
                else
                    b1 += p[i];
            }
            ans = min(ans, abs(a1 - b1));
        }
    }
    for (int i = start; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(start + 1, depth + 1);
            visited[i] = 0;
        }
    }
}

void solve() {
    dfs(1, 0);
    if (ans != 1000000)
        cout << ans;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}