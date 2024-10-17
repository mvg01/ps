#include <iostream>
#include <queue>
using namespace std;

int m, n;
char mat[1001][1001];
int visited[1001][1001];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void init() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
}

int bfs(int y, int x) {
    queue<pair<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        if (yy == m - 1)  //끝에 닿음
            return 1;
        
        for (int k = 0; k < 4; k++) {
            if (yy + dy[k] > m || yy + dy[k]<0 || xx + dx[k]>n || xx + dx[k] < 0)
                continue;
            if (mat[yy + dy[k]][xx + dx[k]] == '0' && !visited[yy + dy[k]][xx + dx[k]]) {
                q.push({ yy + dy[k],xx + dx[k] });
                visited[yy + dy[k]][xx + dx[k]] = 1;
            }
        }
    }
    return 0;
}

int main() 
{
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> mat[i];
        for (int j = 0; j < n; j++) 
            visited[i][j] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (mat[0][i] == '0') {
            if (bfs(0, i)) {
                cout << "YES";
                return 0;
            }
            init();
        }
    }
    cout << "NO";
}