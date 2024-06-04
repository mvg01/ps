#include <bits/stdc++.h>
using namespace std;

int n, m, r1, c1, r2, c2;
char mat[501][501];
int visited[501][501];
int d[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };


//62퍼 틀

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
}

void solve() {
    queue<pair<int, int>>q;
    q.push({ r1,c1 });
    bool chk = 0, end = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (y == r2 && x == c2) {
            visited[y][x] = 0;
            end = 1;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (visited[yy][xx])
                continue;
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (mat[yy][xx] == 'X' && yy == r2 && xx == c2) {
                cout << "YES";
                return;
            }
            if (mat[yy][xx] == '.') {
                q.push({ yy,xx });
                visited[yy][xx] = 1;
            }
        }
    }
    if (!end) {  // r2,c2로 가지도 못함
        cout << "NO";
        return;
    }
    int id = 0;
    for (int i = 0; i < 4; i++) {
        int yy = r2 + d[i][0];
        int xx = c2 + d[i][1];
        if (yy >= n || yy < 0 || xx >= m || xx < 0)
            continue;
        if (mat[yy][xx] == '.' || (yy == r1 && xx == c1))
            id++;
    }
    if (r1 == r2 && c1 == c2) { // 출발점 도착점 같을 땐 '.' 이 하나만 있어도 탈출 가능해짐
        if (id >= 1)
            cout << "YES";
        else
            cout << "NO";
    }
    else {   // 출발점 도착점 다름. '.'이 2개 이상 있어야 함
        if (id >= 2)
            cout << "YES";
        else
            cout << "NO";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}