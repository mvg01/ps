#include <bits/stdc++.h>
using namespace std;

int n, q, res = 0;
int po[7] = { 1,2,4,8,16,32,64 };
int mat[65][65], temp[65][65], ice[65][65], visited[65][65];
int d[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

void input() {
    cin >> n >> q;
    for (int i = 0; i < po[n]; i++) {
        for (int j = 0; j < po[n]; j++)
            cin >> mat[i][j];
    }
}

void change(int sy, int sx, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) 
            temp[sy + j][sx + size - 1 - i] = mat[sy + i][sx + j];
    }
}

void lotate(int x) {  // 시계 방향 90도 회전
    int size = po[x];
    for (int i = 0; i < po[n]; i += size) {
        for (int j = 0; j < po[n]; j += size) 
            change(i, j, size);
    }
    for (int i = 0; i < po[n]; i++) {
        for (int j = 0; j < po[n]; j++) 
            mat[i][j] = temp[i][j];
    }
}

void melt() {
    vector<pair<int, int>>v;
    for (int i = 0; i < po[n]; i++) {
        for (int j = 0; j < po[n]; j++) {
            int cnt = 0;
            if (mat[i][j] == 0) 
                continue;
            for (int k = 0; k < 4; k++) {
                int y = i + d[k][0];
                int x = j + d[k][1];
                if (y >= po[n] || y < 0 || x >= po[n] || x < 0)
                    continue;
                if (mat[y][x] > 0)
                    cnt++;
            }
            if (cnt < 3)
                v.push_back({ i,j });
        }
    }
    for (int i = 0; i < v.size(); i++)
        mat[v[i].first][v[i].second]--;
}

void bfs(int y,int x) {
    queue<tuple<int, int>>q;
    q.push({ y,x });
    visited[y][x] = 1;
    int sum = 1;
    while (!q.empty()) {
        int yy = get<0>(q.front());
        int xx = get<1>(q.front());
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= po[n] || dy < 0 || dx >= po[n] || dx < 0)
                continue;
            if (visited[dy][dx])
                continue;
            if (mat[dy][dx] > 0) {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
                sum++;
            }
        }
    }
    res = max(res, sum);
}

void result() {
    int sum = 0;
    for (int i = 0; i < po[n]; i++) {
        for (int j = 0; j < po[n]; j++)
            sum += mat[i][j];
    }
    cout << sum << '\n';
    for (int i = 0; i < po[n]; i++) {
        for (int j = 0; j < po[n]; j++) {
            if (!visited[i][j] && mat[i][j] != 0)
                bfs(i, j);
        }
    }
    cout << res;
}

void solve() {
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        lotate(x);
        melt();  // 주위에 얼음이 2개 이하면 녹는다.
    }
    result();  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}