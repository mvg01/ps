#include <bits/stdc++.h>
using namespace std;

int r, c;
char mat[114][78];
bool visited[114][78];
pair<int, int>back[114][78];
int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void solve() {
    queue<pair<int, int>>q;
    q.push({ 0,0 });
    visited[0][0] = 1;
    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == r - 1 && x == c - 1)
            break;
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= r || yy < 0 || xx >= c || xx < 0) continue;
            if (visited[yy][xx]) continue;
            if (mat[yy][xx] != '*') {
                q.push({ yy,xx });
                visited[yy][xx] = 1;
                back[yy][xx] = make_pair(y, x);
            }
        }
    }
    // stack으로 역추적
    stack<pair<int, int>>s;
    s.push({ r - 1,c - 1 });
    pair<int, int> cur = make_pair(r - 1, c - 1);
    while (1) {
        if (cur.first == 0 && cur.second == 0)
            break;
        s.push({ back[cur.first][cur.second] });
        cur = back[cur.first][cur.second];
    }
    while (s.size()) {
        cout << s.top().first + 1 << ' ' << s.top().second + 1 << '\n';
        s.pop();
    }
}

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}