#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, m, res = 1000000;
char mat[1001][1001];
int visited[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<tuple<int, int, bool>>q;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> mat[i];
}

void bfs() {
    queue<tuple<int,int,int>>q;
    q.push({ 0,0,0 });
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int brk = get<0>(q.front());
        int y = get<1>(q.front());
        int x = get<2>(q.front());
        int dis = visited[y][x][brk];
        if (y == n - 1 && x == m - 1) {
            res = dis;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= n || yy < 0 || xx >= m || xx < 0) 
                continue;
            if (visited[yy][xx][brk])
                continue;
            if (brk == 0 && mat[yy][xx] == '1') {
                q.push({ 1,yy,xx });
                visited[yy][xx][1] = dis + 1;
            }
            if (mat[yy][xx] == '0') {
                q.push({ brk,yy,xx });
                visited[yy][xx][brk] = dis + 1;
            }
        }
    }
    if (res != 1000000)
        cout << res;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
}
