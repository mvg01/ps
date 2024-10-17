#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int n, m, res = 0;
int mat[501][501] = { 0, };
bool visited[501][501] = { 0, };
int dy[4] = { 1,0,0,-1 };
int dx[4] = { 0,1,-1,0 };

void input() {
    int x1, y1, x2, y2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = min(x1, x2); a <= max(x1, x2); a++) {
            for (int b = min(y1, y2); b <= max(y1, y2); b++) {
                mat[b][a] = 1;
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int a = min(x1, x2); a <= max(x1, x2); a++) {
            for (int b = min(y1, y2); b <= max(y1, y2); b++) {
                mat[b][a] = 2;
            }
        }
    }
}

void bfs() {
    deque<tuple<int, int, int>>dq;  //0-1 bfs
    dq.push_back({ 0,0,0 });
    visited[0][0] = 1;
    while (!dq.empty()) {
        int yy = get<0>(dq.front());
        int xx = get<1>(dq.front());
        int dis = get<2>(dq.front());
        if (yy == 500 && xx == 500) {
            res = dis;
            return;
        }
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int y = yy + dy[i];
            int x = xx + dx[i];
            if (y < 0 || y>500 || x < 0 || x>500)
                continue;
            if (visited[y][x])
                continue;
            if (mat[y][x] == 2) {  //아예 지나갈 수 없는 곳
                visited[y][x] = 1;
                continue;
            }
            if (mat[y][x] == 1) {  //지나갈 순 있지만 라이프가 1 증가함. 따라서 덱의 뒤에 삽입
                visited[y][x] = 1;
                dq.push_back({ y,x,dis + 1 });
            }
            if (mat[y][x] == 0) {  //지나가도 라이프가 증가하지 않음. 덱의 앞에 삽입
                visited[y][x] = 1;
                dq.push_front({ y,x,dis });
            }
        }
    }
    res = -1;
}

void solve() {
    bfs();
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}