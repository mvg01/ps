#include <bits/stdc++.h>
using namespace std;

// 열쇠 소유 여부를 비트마스킹으로 표현 할 수 있다고 한다..
// 시간이나 메모리면에서 차이가 많이 나진 않지만 코드가 길어지고 복잡해짐..

int n, m, sy, sx;
bool visited[2][2][2][2][2][2][51][51];  // 열쇠 소유 여부
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0 } };
char mat[51][51];
vector<pair<int, int>>c;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == '0') {
                sy = i;
                sx = j;
            }
        }
    }
    queue<tuple<bool, bool, bool, bool, bool, bool, int, int, int>>q;
    q.push({ 0,0,0,0,0,0,sy,sx,0 });
    visited[0][0][0][0][0][0][sy][sx] = 1;
    while (!q.empty()) {
        bool a = get<0>(q.front());
        bool b = get<1>(q.front());
        bool c = get<2>(q.front());
        bool d = get<3>(q.front());
        bool e = get<4>(q.front());
        bool f = get<5>(q.front());
        int y = get<6>(q.front());
        int x = get<7>(q.front());
        int dis = get<8>(q.front());
        q.pop();
        if (mat[y][x] == '1') {
            cout << dis;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + dir[i][0];
            int xx = x + dir[i][1];
            bool a1 = a;
            bool b1 = b;
            bool c1 = c;
            bool d1 = d;
            bool e1 = e;
            bool f1 = f;
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited[a][b][c][d][e][f][yy][xx])
                continue;
            if (mat[yy][xx] >= 'a' && mat[yy][xx] <= 'f') {
                if (mat[yy][xx] == 'a')
                    a1 = 1;
                if (mat[yy][xx] == 'b')
                    b1 = 1;
                if (mat[yy][xx] == 'c')
                    c1 = 1;
                if (mat[yy][xx] == 'd')
                    d1 = 1;
                if (mat[yy][xx] == 'e')
                    e1 = 1;
                if (mat[yy][xx] == 'f')
                    f1 = 1;
                q.push({ a1,b1,c1,d1,e1,f1,yy,xx,dis + 1 });
                visited[a1][b1][c1][d1][e1][f1][yy][xx] = 1;
            }
            else {
                if (mat[yy][xx] >= 'A' && mat[yy][xx] <= 'F') {
                    if (mat[yy][xx] == 'A' && !a) 
                        continue;
                    if (mat[yy][xx] == 'B' && !b)
                        continue;
                    if (mat[yy][xx] == 'C' && !c)
                        continue;
                    if (mat[yy][xx] == 'D' && !d)
                        continue;
                    if (mat[yy][xx] == 'E' && !e)
                        continue;
                    if (mat[yy][xx] == 'F' && !f)
                        continue;
                }
                if (mat[yy][xx] != '#') {
                    q.push({ a1,b1,c1,d1,e1,f1,yy,xx,dis + 1 });
                    visited[a1][b1][c1][d1][e1][f1][yy][xx] = 1;
                }
            }
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}