#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, h, w, sr, sc, fr, fc;
int mat[1001][1001];
bool visited[1001][1001];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    cin >> h >> w >> sr >> sc >> fr >> fc;
    sr--; sc--; fr--; fc--;
}

bool chk_move(int y, int x, int d) {
    if (d == 0) {  //  y축으로 +1
        for (int i = x; i < x + w; i++) {  // y+h를 y좌표로 갖는 x축 중에서 벽이 있는지 살핀다.
            if (mat[y + h][i] == 1)
                return true;
        }
    }
    if (d == 1) {  // x축으로 +1
        for (int i = y; i < y + h; i++) {  // x+w를 x좌표로 갖는 y축 중에서 벽이 있는지 살핀다.
            if (mat[i][x + w] == 1)
                return true;
        }
    }
    if (d == 2) {  // x축으로 -1
        for (int i = y; i < y + h; i++) {  // x-1를 x좌표로 갖는 y축 중에서 벽이 있는지 살핀다.
            if (mat[i][x - 1] == 1)
                return true;
        }
    }
    if (d == 3) {  // y축으로 -1
        for (int i = x; i < x + w; i++) {  // y-1를 y좌표로 갖는 x축 중에서 벽이 있는지 살핀다.
            if (mat[y - 1][i] == 1) 
                return true;
        }
    }
    return false;
}

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ sr,sc,0 });
    visited[sr][sc] = 1;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        if (y == fr && x == fc) {
            cout << cnt;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy < 0 || xx < 0 || yy + h > n || xx + w > m)  // (yy,xx)가 왼쪽 위의 점인 직사각형을 만들 수 없는 경우
                continue;
            if (visited[yy][xx])
                continue;
            bool chk = chk_move(y, x, i);
            if (chk)  // 사각형 범위 내에 벽이 있다면 여기서 true 처리 될 것
                continue;
            q.push({ yy,xx,cnt + 1 });
            visited[yy][xx] = 1;
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