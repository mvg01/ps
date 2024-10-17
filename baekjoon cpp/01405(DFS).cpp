#include <iostream>
using namespace std;

int n;
int dir[4][2] = { {0,1},{0,-1 },{-1,0},{1,0} };  //동서남북
int visited[29][29];
double d[4], ans = 0;

void input() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        cin >> d[i];
        d[i] /= 100;
    }
}

void init() {
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 29; j++)
            visited[i][j] = 0;
    }
}

void dfs(int cnt, int y, int x, double per) {
    if (cnt == n) {
        ans += per;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int yy = y + dir[i][0];
        int xx = x + dir[i][1];
        if (!visited[yy][xx]) {  // 방문하지 않았던 곳으로 가는것이 단순한 경로
            visited[yy][xx] = 1;
            dfs(cnt + 1, yy, xx, per * d[i]);
            visited[yy][xx] = 0;
        }
    }
}

void solve() {
    for (int i = 0; i < 4; i++) {  // 4방향 기준 시작 동서남북 순으로 
        visited[14][14] = 1;
        int y = 14 + dir[i][0];
        int x = 14 + dir[i][1];
        visited[y][x] = 1;
        dfs(1, y, x, d[i]);
        init();  // 방문 배열 초기화
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(10);
    input();
    solve();
}