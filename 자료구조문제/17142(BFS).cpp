#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int n, m, res = 1000000;
int mat[51][51];
int visited[51][51];
bool selected[11];
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };
vector<pair<int, int>>virus;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
                virus.push_back({ i,j });
        }
    }
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1)
                visited[i][j] = 1;
            else
                visited[i][j] = 0;
        }
    }
}

void bfs() {
    int max_time = -1;
    queue<tuple<int, int, int>>q;  // 활성화된 바이러스 y,x,시간
    for (int i = 0; i < virus.size(); i++) {
        if (selected[i]) {
            visited[virus[i].first][virus[i].second] = 1;
            q.push({ virus[i].first ,virus[i].second,0 });
        }
    }
    while (!q.empty()) {
        int yy = get<0>(q.front());
        int xx = get<1>(q.front());
        int dis = get<2>(q.front());
        q.pop();
        if (mat[yy][xx] != 2) {  // 바이러스 자리였다면 시간 체크 X
            max_time = max(max_time, dis);
        }
        for (int i = 0; i < 4; i++) {
            int y = yy + dy[i];
            int x = xx + dx[i];
            if (visited[y][x])
                continue;
            if (y < 0 || y >= n || x < 0 || x >= n)
                continue;
            if (mat[y][x] != 1) {
                q.push({ y,x,dis + 1 });
                visited[y][x] = 1;
            }
        }
    }
    bool chk = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (mat[i][j] == 0)
                    chk = 1;
            }
        }
    }
    if (!chk) {
        max_time = max(max_time, 0);  // 빈 곳이 없는 경우
        res = min(res, max_time);
    }
}

void start_virus(int start, int cnt) {  // 활성 바이러스 선택
    if (cnt == m) {
        init();
        bfs();
        return;
    }
    for (int i = start; i < virus.size(); i++) {
        if (!selected[i]) {
            selected[i] = 1;
            start_virus(i, cnt + 1);
            selected[i] = 0;
        }
    }
}

void solve() {
    start_virus(0, 0);
    if (res != 1000000)
        cout << res;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}