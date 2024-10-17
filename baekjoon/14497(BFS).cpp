#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

// 0-1 bfs 

char mat[301][301];
int visited[301][301];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int n, m, x_1, y_1, x_2, y_2;
void input() {
    cin >> n >> m >> y_1 >> x_1 >> y_2 >> x_2;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    x_1--; y_1--; x_2--; y_2--;
}

void solve() {
    deque<pair<int, int>>dq;
    dq.push_back({ y_1,x_1 });
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++)
            visited[i][j] = INF;
    }
    visited[y_1][x_1] = 1;
    while (!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        int c = visited[y][x];
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (mat[yy][xx] == '1' && visited[yy][xx] > c + 1) {
                visited[yy][xx] = c + 1;
                dq.push_back({ yy,xx });
            }
            if (mat[yy][xx] == '0' && visited[yy][xx] > c) {
                visited[yy][xx] = c;
                dq.push_front({ yy,xx });
            }
            if (yy == y_2 && xx == x_2) {
                cout << c;
                return;
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