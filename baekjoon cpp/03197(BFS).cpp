#include <bits/stdc++.h>
using namespace std;

int r, c, day = 1;
char mat[1501][1501];
int p[2250001];
int vis[1501][1501];
int d[4][2] = { {0,1},{-1,0},{1,0},{0,-1} };
vector<int>l;
queue<pair<int, int>>q, next_q;

void init() {
    for (int i = 1; i <= 2250000; i++) p[i] = i;
}

int getParent(int x) {
    if (x == p[x]) return x;
    else return p[x] = getParent(p[x]);
}

void setUnion(int a, int b) {
    int aa = getParent(a);
    int bb = getParent(b);
    if (aa < bb)
        p[aa] = bb;
    else
        p[bb] = aa;
}

void solve() {
    init();
    while (q.size()) {
        while (q.size()) {  // 물 끼리 union
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int yy = y + d[i][0];
                int xx = x + d[i][1];
                if (yy >= r || yy < 0 || xx >= c || xx < 0)
                    continue;
                if (mat[yy][xx] == '.') 
                    setUnion(c * y + x + 1, c * yy + xx + 1);
                if (vis[yy][xx])
                    continue;
                if (mat[yy][xx] == 'X') {  // 녹을 빙하는 다음 bfs 턴의 물이 된다.
                    vis[yy][xx] = 1;
                    next_q.push({ yy,xx });
                }
            }
        }
        if (getParent(l[0]) == getParent(l[1])) {
            cout << day - 1;
            return;
        }
        day++;
        while (next_q.size()) {  // 녹을 빙하를 물로 전환 후, 다시 union 준비
            auto [y, x] = next_q.front();
            next_q.pop();
            mat[y][x] = '.';
            q.push({ y,x });
        }
    }
}

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> mat[i];
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 'L') {
                l.push_back(c * i + j + 1);  // 백조 위치
                mat[i][j] = '.';  // 백조는 물
                q.push({ i,j });
                vis[i][j] = 1;
            }
            else if (mat[i][j] == '.') {
                q.push({ i,j });
                vis[i][j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}