#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b;
int mat[1001][1001];
bool visited[1001][1001];
int dir[2][4] = { {1,-1,0,0},{0,0,-1,1} };
priority_queue<pair<int,pair<int, int>>>pq;
vector<pair<int, int>>v;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                pq.push({ mat[i][j],{i,j} });
                visited[i][j] = 1;
            }
        }
    }
    cin >> k;
}

void bfs() {
    while (k != 0) {
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        v.push_back({ y+1,x+1 });
        pq.pop();
        k--;
        for (int i = 0; i < 4; i++) {
            int yy = y + dir[0][i];
            int xx = x + dir[1][i];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            pq.push({ mat[yy][xx],{yy,xx} });
            visited[yy][xx] = 1;
        }
    }
}

void solve() {
    bfs();
    for (int i = 0; i < v.size(); i++) 
        cout << v[i].first << ' ' << v[i].second << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}