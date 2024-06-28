#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int m, n, v, x, y, res = -1, res_t = 0;
int mat[101][101];
int visited[101][101];
int visited2[101][101];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
vector<pair<int, pair<int, int>>>t;

void input() {
    cin >> n >> m >> v >> y >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cin >> mat[i][j];
    }
    for (int i = 0; i < v; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        t.push_back({ c, { a,b } });
    }
    x--; y--;
}

void solve() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            visited[i][j] = INF;
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < t.size(); i++) {
        visited[t[i].second.first][t[i].second.second] = t[i].first;
        pq.push({ t[i].first,{t[i].second.first,t[i].second.second} });
    }
    while (!pq.empty()) {
        int time = pq.top().first;
        int xx = pq.top().second.second;
        int yy = pq.top().second.first;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int dx = xx + d[i][1];
            int dy = yy + d[i][0];
            if (dy >= m || dy < 0 || dx >= n || dx < 0)
                continue;
            if (visited[dy][dx] > time + 1) {
                visited[dy][dx] = time + 1;
                pq.push({ time + 1,{dy,dx} });
            }
        }
    }
    for (int i = 0; i < t.size(); i++)  // 화산으로 못감
        visited2[t[i].second.first][t[i].second.second] = 1;

    queue<tuple<int, int, int>>q;
    q.push({ y,x,0 });
    visited2[y][x] = 1;
    while (!q.empty()) {
        int yy = get<0>(q.front());
        int xx = get<1>(q.front());
        int tt = get<2>(q.front());
        q.pop();
        if (res < mat[yy][xx]) {
            res = mat[yy][xx];
            res_t = tt;
        }
        for (int i = 0; i < 4; i++) {
            int dx = xx + d[i][1];
            int dy = yy + d[i][0];
            if (dy >= m || dy < 0 || dx >= n || dx < 0)
                continue;
            if (visited2[dy][dx])
                continue;
            if (visited[dy][dx] > tt + 1) {  // 화산 쇄설류보다 빠르게 도착가능한
                q.push({ dy,dx,tt + 1 });
                visited2[dy][dx] = 1;
            }
        }
    }
    cout << res << ' ' << res_t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}