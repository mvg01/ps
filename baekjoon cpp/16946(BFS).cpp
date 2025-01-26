#include <bits/stdc++.h>
using namespace std;

int n, m, idx = 1, ans;
char mat[1001][1001];
bool vis[1001][1001];
pair<int, int>cnt[1001][1001];  // 연결된 곳 개수, 인덱스
int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void group(int y, int x) {
    vis[y][x] = 1;
    queue<pair<int, int>>q;
    vector<pair<int, int>>v;
    q.push({ y,x });
    v.push_back({ y,x });
    int c = 1;
    while(q.size()) {
        auto [yy, xx] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= n || dy < 0 || dx >= m || dx < 0)
                continue;
            if (vis[dy][dx])
                continue;
            if (mat[dy][dx] == '0') {
                vis[dy][dx] = 1;
                q.push({ dy,dx });
                v.push_back({ dy,dx });
                c++;
            }
        }
    }
    for (auto i : v)
        cnt[i.first][i.second] = { c,idx };
    idx++;
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '0' && !vis[i][j])  // 0끼리 그룹화 (연결된 개수와 인덱싱)
                group(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = 0;
            if (mat[i][j] == '1') {
                ans++;
                set<int>s;
                for (int k = 0; k < 4; k++) {
                    int yy = i + d[k][0];
                    int xx = j + d[k][1];
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    if (mat[yy][xx] == '0') {
                        if (s.find(cnt[yy][xx].second) == s.end()) {
                            ans += cnt[yy][xx].first;
                            s.insert(cnt[yy][xx].second);
                        }
                    }
                }
            }
            cout << ans % 10;
        }
        cout << '\n';
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}