#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, x, y;
string s;
char mat[1001][1001];
char res[1001][1001];
int visited[1001][1001];
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
    cin >> y >> x;
    y--; x--;
    cin >> s;
}

void bfs(int yy, int xx) {
    char ca = mat[yy][xx];
    queue<pair<int, int>>q;
    q.push({ yy,xx });
    visited[yy][xx] = 1;
    res[yy][xx] = '.';
    while (!q.empty()) {
        int _y = q.front().first;
        int _x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int cy = _y + dy[i];
            int cx = _x + dx[i];
            if (cy >= r || cy < 0 || cx >= c || cx < 0)
                continue;
            if (visited[cy][cx])
                continue;
            if (mat[cy][cx] == ca) {
                q.push({ cy,cx });
                visited[cy][cx] = 1;
                res[cy][cx] = '.';
            }
        }
    }
}
    
void solve() {
    int len = s.length();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            res[i][j] = '#';
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'W')
            bfs(y, x);
        else if (s[i] == 'U')
            y--;
        else if (s[i] == 'D')
            y++;
        else if (s[i] == 'L')
            x--;
        else if (s[i] == 'R')
            x++;
    }
    res[y][x] = '.';
    res[y-1][x] = '.';
    res[y][x+1] = '.';
    res[y][x-1] = '.';
    res[y+1][x] = '.';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << res[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}