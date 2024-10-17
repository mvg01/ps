#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, ans = 0;
char mat[51][51];
int dir[6][2] = { {-1,0},{-1,1},{0,1},{1,0},{1,-1},{0,-1} };
int visited[51][51];

void bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        int c = visited[yy][xx];
        ans = max(ans, 1);
        q.pop();
        for (int i = 0; i < 6; i++) {
            int dy = yy + dir[i][0];
            int dx = xx + dir[i][1];
            if (dy >= n || dy < 0 || dx >= n || dx < 0)
                continue;
            if (mat[dy][dx] == '-')
                continue;
            if (visited[dy][dx] == c) {  // 현재 좌표 색인 C와 같은 색
                cout << 3;
                exit(0);
            }
            if (visited[dy][dx] == 0) {
                q.push({ dy,dx });
                visited[dy][dx] = (c == 1) ? 2 : 1;
                ans = 2;
            }
        }
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'X' && !visited[i][j]) {
                visited[i][j] = 1;
                bfs(i, j);
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}

/*
3
-X-
-XX
X--
ans=2

4
XXXX
---X
XX-X
X--X
ans=3

4
-XXX
X--X
X-X-
XX--
ans=3
*/