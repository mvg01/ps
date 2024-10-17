#include <bits/stdc++.h>
using namespace std;

int h, w, n, dy, dx, zy, zx;
char mat[21][21];
char d[20][2];
int dir[4][2] = { {-1,0}, {0,-1}, {1,0}, {0,1} };

void input() {
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        cin >> mat[i];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i][0] >> d[i][1];
}

pair<int, int> f(char a[]) {
    pair<int, int>p;
    if (a[0] == 'W')
        p.first = 0;
    else if (a[0] == 'A')
        p.first = 1;
    else if (a[0] == 'S')
        p.first = 2;
    else if (a[0] == 'D')
        p.first = 3;
    if (a[1] == 'W')
        p.second = 0;
    else if (a[1] == 'A')
        p.second = 1;
    else if (a[1] == 'S')
        p.second = 2;
    else if (a[1] == 'D')
        p.second = 3;
    return p;
}

void solve() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == 'D') {
                dy = i;
                dx = j;
            }
            if (mat[i][j] == 'Z') {
                zy = i;
                zx = j;
            }
        }
    }
    vector<char>v;
    queue<tuple<int, int, int, vector<char>>>q;
    q.push({ dy,dx,0,v });
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int idx = get<2>(q.front());
        vector<char>v1 = get<3>(q.front());
        vector<char>v2 = get<3>(q.front());
        q.pop();
        if (y == zy && x == zx) {
            cout << "YES\n";
            for (auto i : v1) cout << i;
            return;
        }
        if (idx == n)
            continue;
        pair<int, int>p = f(d[idx]);
        int yy = y + dir[p.first][0];
        int xx = x + dir[p.first][1];
        if (yy < h && yy >= 0 && xx < w && xx >= 0) {
            if (mat[yy][xx] != '@') {
                v1.push_back(d[idx][0]);
                q.push({ yy,xx,idx + 1,v1 });
            }
        }
        yy = y + dir[p.second][0];
        xx = x + dir[p.second][1];
        if (yy < h && yy >= 0 && xx < w && xx >= 0) {
            if (mat[yy][xx] != '@') {
                v2.push_back(d[idx][1]);
                q.push({ yy,xx,idx + 1,v2 });
            }
        }
    }
    cout << "NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}