#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, m, r;
int mat[101][101];
int t[101];

void input() {
    int a, b, c;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++)
            mat[i][j] = INF;
    }
    for (int i = 0; i < r; i++) {
        cin >> a >> b >> c;
        mat[a][b] = c;
        mat[b][a] = c;
    }
}

void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        cnt += t[i];
        bool visited[101] = { 0 };
        queue<pair<int, int>>q;
        visited[i] = 1;
        q.push({ 0,i });
        while (!q.empty()) {
            int dis = q.front().first;
            int point = q.front().second;
            q.pop();
            for (int j = 1; j <= n; j++) {
                if (visited[j])
                    continue;
                if (dis + mat[i][j] <= m) {
                    q.push({ dis + mat[i][j],j });
                    cnt += t[j];
                    visited[j] = 1;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}