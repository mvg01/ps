#include <bits/stdc++.h>
using namespace std;

int h, w;
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char mat[201][201];
bool visited[201][201];
bool k[27];
pair<int, int> s;
queue<pair<int, int> > q;
vector<pair<int, int> > door;
vector<pair<int, int> > ans;

void door_chk() {
    for (int i = 0; i < door.size(); i++) {
        if (k[mat[door[i].first][door[i].second] + 32 - 'a'] && !visited[door[i].first][door[i].second]) {
            q.push({door[i].first, door[i].second});
            visited[door[i].first][door[i].second] = 1;
            ans.push_back({door[i].first, door[i].second});
        }
    }
}

void solve() {
    q.push({s.first, s.second});
    ans.push_back({s.first, s.second});
    visited[s.first][s.second] = 1;
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] >= 'a' && mat[yy][xx] <= 'z') {
                q.push({yy, xx});
                visited[yy][xx] = 1;
                ans.push_back({yy, xx});
                k[mat[yy][xx] - 'a'] = 1;
                door_chk();
            } else if (mat[yy][xx] >= 'A' && mat[yy][xx] <= 'Z') {
                door.push_back({yy, xx});
                door_chk();
            } else if (mat[yy][xx] == '*') {
                q.push({yy, xx});
                visited[yy][xx] = 1;
                ans.push_back({yy, xx});
            } else if (mat[yy][xx] == '!') {
                ans.push_back({yy, xx});
                cout << ans.size() << '\n';
                for (auto j: ans)
                    cout << j.first + 1 << ' ' << j.second + 1 << '\n';
                return;
            }
        }
    }
}

void input() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> mat[i];
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == '@')
                s = {i, j};
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}