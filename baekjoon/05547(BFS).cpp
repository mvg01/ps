#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int w, h;
int mat[105][105];
int visited[105][105];
int dir1[6][2] = { {-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1} };  // y가 홀수일 떄
int dir2[6][2] = { {-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0} };  // y가 짝수일 때
int bfs(int y, int x) {
    int ans = 0;
    queue<pair<int, int>>q;
    q.push({ y,x });
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int dy, dx;
            if (yy % 2 == 1) {
                dy = yy + dir1[i][0];
                dx = xx + dir1[i][1];
            }
            else {
                dy = yy + dir2[i][0];
                dx = xx + dir2[i][1];
            }
            if (dy > h + 1 || dy < 0 || dx > w + 1 || dx < 0) //범위를 (0,0) ~ (n+1,n+1)로
                continue;

            if (mat[dy][dx] == 1)   // 흰색과 회색이 닿음
                ans++;
            
            else if (!visited[dy][dx] && mat[dy][dx] == 0) {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
            }
        }
    }
    return ans;
}

void input() {
    cin >> w >> h;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cin >> mat[i][j];
    }
    cout << bfs(0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}